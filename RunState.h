//
// Created by albani on 10/10/26.
//

#ifndef REDOTCPPGAME_RUNSTATE_H
#define REDOTCPPGAME_RUNSTATE_H
#include "PlayerState.h"

namespace godot {
    class Marine;
    class RunState : public PlayerState
    {
    private:
        Marine& marine;
    public:
        explicit RunState(Marine& marine);
        ~RunState() override;

        void Enter() override;
        void Update(double delta) override;
        void Exit() override;
    };
}


#endif //REDOTCPPGAME_RUNSTATE_H
