// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

// Copied from https://github.com/EVerest/libfsm/blob/draft/v2/include/fsm/v2/fsm.hpp

#pragma once

#include <type_traits>
#include <utility>
#include <vector>

namespace fsm::v2 {

namespace detail {

// detection idiom, see https://blog.tartanllama.xyz/detection-idiom/
template <typename T, typename = void> struct output_type { using type = void; };

template <typename T> struct output_type<T, std::void_t<decltype(std::declval<T>().output)>> {
    using type = decltype(std::declval<T>().output);
};

template <typename T> using output_type_t = typename output_type<T>::type;

struct FeedResult {

    FeedResult() = default;
    FeedResult(bool transition) : m_state(transition ? State::Transition : State::NoTransition) {
    }

    operator bool() const {
        return m_state != State::Unhandled;
    }

    bool transitioned() const {
        return (m_state == State::Transition);
    }

private:
    enum class State {
        Unhandled,
        Transition,
        NoTransition,
    };
    State m_state{State::Unhandled};
};
} // namespace detail

template <typename OutputType> struct FeedResult : public detail::FeedResult {
    using detail::FeedResult::FeedResult;

    FeedResult(OutputType feed_output, bool transition) :
        detail::FeedResult(transition), output(std::move(feed_output)) {
    }

    OutputType output; // we're requiring this to be default constructible?
};

template <> struct FeedResult<void> : public detail::FeedResult { using detail::FeedResult::FeedResult; };

template <typename StateType> class FSM {
public:
    using StateContainerType = typename StateType::ContainerType;
    // using StateIDType = std::invoke_result_t<decltype(&StateType::get_id), StateType>;
    FSM(StateContainerType initial_state) : m_current_state(std::move(initial_state)) {
        m_current_state->enter();
    }

    template <typename... Args> auto feed(Args&&... args) {
        auto result = m_current_state->feed(std::forward<Args>(args)...);

        using OutputType = detail::output_type_t<decltype(result)>;

        if (result.unhandled) {
            return FeedResult<OutputType>();
        }

        const bool transitioned = (result.new_state != nullptr);

        if (transitioned) {
            m_current_state->leave();
            m_current_state = std::move(result.new_state);
            m_current_state->enter();
        }

        if constexpr (std::is_same_v<OutputType, void>) {
            return FeedResult<OutputType>(transitioned);
        } else {
            return FeedResult<OutputType>(std::move(result.output), transitioned);
        }
    }

    auto get_current_state_id() const {
        return m_current_state->get_id();
    }

    ~FSM() {
        m_current_state->leave();
    }

private:
    StateContainerType m_current_state;
};

namespace detail {
template <typename StateStackType> void unroll_child_states(StateStackType& state_stack) {
    while (true) {
        auto& leaf = state_stack.back();
        leaf->enter();

        auto child = leaf->get_initial();

        if (child == nullptr) {
            break;
        }

        state_stack.emplace_back(std::move(child));
    }
}

} // namespace detail

template <typename StateType> class NestedFSM {
public:
    using StateContainerType = typename StateType::ContainerType;

    NestedFSM(StateContainerType initial_state) {
        m_state_stack.emplace_back(std::move(initial_state));
        detail::unroll_child_states(m_state_stack);
    }

    template <typename... Args> auto feed(Args&&... args) {
        auto leaf = m_state_stack.rbegin();

        auto result = (*leaf)->feed(std::forward<Args>(args)...);
        using OutputType = detail::output_type_t<decltype(result)>;

        auto next_state = std::next(leaf);

        // descend stack as long as no state handles the event or the
        // stack's bottom is reached
        while (result.unhandled and (next_state != m_state_stack.rend())) {
            // check next state on stack
            // FIXME (aw): this will break with rvalue reference, as
            // they are moved multiple times
            result = (*next_state)->feed(std::forward<Args>(args)...);
            next_state = std::next(next_state);
        }

        // if not handled at all, don't do anything at all
        if (result.unhandled) {
            return FeedResult<OutputType>();
        }

        const bool transitioned = (result.new_state != nullptr);

        if (transitioned) {
            while (leaf != next_state) {
                (*leaf)->leave();
                leaf = std::next(leaf);

                m_state_stack.pop_back();
            }

            m_state_stack.emplace_back(std::move(result.new_state));
            detail::unroll_child_states(m_state_stack);
        }

        if constexpr (std::is_same_v<OutputType, void>) {
            return FeedResult<OutputType>(transitioned);
        } else {
            return FeedResult<OutputType>(std::move(result.output), transitioned);
        }
    }

    // NOTE (aw): could be computed along the feed
    auto get_current_state_id() const {
        using StateIDType = decltype(std::declval<StateType>().get_id());

        std::vector<StateIDType> current_ids;
        current_ids.reserve(m_state_stack.size());

        for (const auto& state : m_state_stack) {
            current_ids.emplace_back(state->get_id());
        }

        return current_ids;
    }

    ~NestedFSM() {
        // leave all the states in order
        for (auto leaf = m_state_stack.rbegin(); leaf != m_state_stack.rend();) {
            (*leaf)->leave();
            leaf = std::next(leaf);
            m_state_stack.pop_back();
        }
    }

private:
    std::vector<StateContainerType> m_state_stack;
};

} // namespace fsm::v2