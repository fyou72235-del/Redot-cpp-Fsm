//
// Created by albani on 10/9/26.
//

#include "StateMachine.h"


namespace godot {
    StateMachine::StateMachine() = default;

    StateMachine::~StateMachine() = default;

    void StateMachine::ChangeState(std::unique_ptr<PlayerState> new_state) {
        pendingState = std::move(new_state);
    }

    void StateMachine::UpdateState(double delta) {
        if (state) {
            state->Update(delta);
        }
        if (pendingState) {
            if (state) {
                state->Exit();
            }

            state = std::move(pendingState);
            state->Enter();
        }
    }
}
