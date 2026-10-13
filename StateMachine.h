//
// Created by albani on 10/9/26.
//

#ifndef REDOTCPPGAME_STATEMACHINE_H
#define REDOTCPPGAME_STATEMACHINE_H
#include <memory>
#include <godot_cpp/classes/engine.hpp>

#include "PlayerState.h"

namespace godot {
    class StateMachine{
    private:
        std::unique_ptr<PlayerState> state;
        std::unique_ptr<PlayerState> pendingState;
    public:
        StateMachine();
        ~StateMachine();
        void ChangeState(std::unique_ptr<PlayerState> new_state);

        void UpdateState(double delta);
    };

}


#endif //REDOTCPPGAME_STATEMACHINE_H
