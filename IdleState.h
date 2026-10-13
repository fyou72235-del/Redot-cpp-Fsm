//
// Created by albani on 10/9/26.
//

#ifndef REDOTCPPGAME_IDLESTATE_H
#define REDOTCPPGAME_IDLESTATE_H

#include <godot_cpp/classes/engine.hpp>
#include "PlayerState.h"

namespace godot {
    class Marine;
    class IdleState : public PlayerState{
    private:
        Marine& marine;
    public:
        explicit IdleState(Marine& marine);
        ~IdleState() override;

        void Enter() override;
        void Update(double delta) override;
        void Exit() override;
    };
}


#endif //REDOTCPPGAME_IDLESTATE_H
