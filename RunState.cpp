//
// Created by albani on 10/10/26.
//

#include "RunState.h"

#include "FallState.h"
#include "JumpState.h"
#include "Marine.h"

namespace godot {
    RunState::RunState(Marine &marine) : marine(marine) {

    }

    RunState::~RunState() {

    }

    void RunState::Enter() {
        UtilityFunctions::print("Run");
        marine.animated_sprite->play("Run");
    }

    void RunState::Update(double delta) {
        marine.velocity = Vector2(marine.dir * marine.speed,
            marine.velocity.y);

        marine.set_velocity(marine.velocity);

        if (marine.is_on_floor() && marine.dir == 0) {
            marine.state_machine.ChangeState(std::make_unique<godot::IdleState>(marine));
        }
        if (marine.is_on_floor() && marine.input->is_action_just_pressed("ui_up")) {
            marine.state_machine.ChangeState(std::make_unique<godot::JumpState>(marine));
        }
        if (marine.is_on_floor() == false) {
            marine.state_machine.ChangeState(std::make_unique<godot::FallState>(marine));
        }


    }

    void RunState::Exit() {

    }
}
