//
// Created by albani on 10/10/26.
//

#ifndef REDOTCPPGAME_JUMPSTATE_H
#define REDOTCPPGAME_JUMPSTATE_H
#include "PlayerState.h"

namespace godot {
    class Marine;
    class JumpState : public PlayerState{
    public:
        explicit JumpState(Marine& marine);
        ~JumpState() override;

        void Enter() override;
        void Update(double delta) override;
        void Exit() override;
        void ApplyGravity(double delta);
    private:
        Marine& marine;
    };
}


#endif //REDOTCPPGAME_JUMPSTATE_H
