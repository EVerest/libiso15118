// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/io/poll_manager.hpp>

#include <type_traits>
#include <vector>

#include <sys/eventfd.h>
#include <sys/poll.h>
#include <unistd.h>

#include <iso15118/detail/helper.hpp>

namespace iso15118::io {

struct PollSet {
    // FIXME (aw): probably it is not the responsibility of the PollSet to care about the mutex
    PollSet(const std::map<int, PollManager::ReadCallback>&, int event_fd);
    size_t size;
    std::unique_ptr<struct pollfd[]> fds;
    std::vector<PollManager::ReadCallback*> callbacks;
};

PollSet::PollSet(const std::map<int, PollManager::ReadCallback>& map, int event_fd) :
    size(map.size() + 1), fds(std::make_unique<struct pollfd[]>(size)), callbacks(map.size(), nullptr) {

    auto index = 0;
    for (auto map_it = map.begin(); index < map.size(); index++, map_it++) {
        fds[index].fd = map_it->first;
        fds[index].events = POLLIN;
        callbacks[index] = &map_it->second;
    }

    // index should be now (size - 1) which is reserved for our event_fd
    fds[index].fd = event_fd;
    fds[index].events = POLLIN;
}

static PollSet create_poll_set_with_lock(std::mutex& map_mtx, const std::map<int, PollManager::ReadCallback>& map,
                                         int event_fd) {
    std::lock_guard lock(map_mtx);
    return PollSet(map, event_fd);
}

PollManager::PollManager() {
    event_fd = eventfd(0, 0);
    if (event_fd == -1) {
        log_and_throw("Failed to create eventfd");
    }
}

void PollManager::register_fd(int fd, ReadCallback& read_callback) {
    std::lock_guard lock(map_mtx);
    registered_fds.emplace(fd, read_callback);
    current_event = EventType::MODIFIED_FD;
    eventfd_write(event_fd, 1);
}

void PollManager::unregister_fd(int fd) {
    std::lock_guard lock(map_mtx);
    registered_fds.erase(fd);
    current_event = EventType::MODIFIED_FD;
    eventfd_write(event_fd, 1);
}

void PollManager::start() {
    if (loop_thread.joinable()) {
        log_and_throw("Tried to start the PollManager, altough it is already running");
    }
    loop_thread = std::thread(&PollManager::loop, this);
}

void PollManager::stop() {
    if (!loop_thread.joinable()) {
        log_and_throw("Tried to stop the PollManager, although it wasn't started");
    }

    eventfd_write(event_fd, 1);
    current_event = EventType::NONE;
    loop_thread.join();
}

void PollManager::loop() {

    auto set = create_poll_set_with_lock(map_mtx, registered_fds, event_fd);

    while (true) {
        const auto ret = poll(set.fds.get(), set.size, -1);

        if (ret == -1) {
            log_and_throw("Poll failed\n");
        }

        // first check for events
        if (set.fds[set.size - 1].revents & POLLIN) {
            eventfd_t tmp;
            eventfd_read(event_fd, &tmp);

            const auto event = current_event;
            current_event = EventType::NONE;
            switch (event) {
            case EventType::STOP:
                return;
            case EventType::MODIFIED_FD:
                set = create_poll_set_with_lock(map_mtx, registered_fds, event_fd);
                continue;
            }
        }

        // no event happened
        for (auto i = 0; i < set.callbacks.size(); ++i) {
            if (set.fds[i].revents & POLLIN) {
                (*set.callbacks[i])();
            }
        }
    }
}

} // namespace iso15118::io
