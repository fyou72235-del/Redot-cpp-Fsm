//
// Created by albani on 10/10/26.
//

#ifndef REDOTCPPGAME_FALLSTATE_H
#define REDOTCPPGAME_FALLSTATE_H
#include "PlayerState.h"

namespace godot {
    class Marine;
    class FallState : public PlayerState{
    public:
        explicit FallState(Marine& marine);
        ~FallState() override;

        void Enter() override;
        void Update(double delta) override;
        void Exit() override;
    private:
        Marine& marine;
    };
}


#endif //REDOTCPPGAME_FALLSTATE_H
