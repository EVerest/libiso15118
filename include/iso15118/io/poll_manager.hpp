// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <functional>
#include <map>
#include <mutex>
#include <thread>

namespace iso15118::io {

enum class EventType : uint8_t {
    NONE,
    MODIFIED_FD,
    STOP,
};

class PollManager {
public:
    using ReadCallback = const std::function<void()>;
    PollManager();
    void start();
    void stop();
    void register_fd(int fd, ReadCallback& read_callback);
    void unregister_fd(int fd);

private:
    void loop();
    std::thread loop_thread;
    std::map<int, ReadCallback> registered_fds;

    std::mutex map_mtx;

    int event_fd{-1};
    // FIXME (aw): the event handling is not thread-safe!!
    EventType current_event{EventType::NONE};
};

} // namespace iso15118::io
