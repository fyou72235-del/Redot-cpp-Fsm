//
// Created by albani on 10/9/26.
//

#include "IdleState.h"

#include "FallState.h"
#include "JumpState.h"
#include "Marine.h"
#include "RunState.h"


godot::IdleState::IdleState(Marine &marine) : marine(marine) {

}

godot::IdleState::~IdleState() {
}

void godot::IdleState::Enter() {
    UtilityFunctions::print("Idle");
    marine.animated_sprite->play("Idle");
}

void godot::IdleState::Update(double delta) {
    marine.velocity = Vector2(0.0f,
        marine.velocity.y);

    marine.set_velocity(marine.velocity);

    if (!marine.is_on_floor()) {
        marine.state_machine.ChangeState(std::make_unique<godot::FallState>(marine));
    }

    else if (marine.is_on_floor() && marine.dir != 0)
    {
        marine.state_machine.ChangeState(std::make_unique<godot::RunState>(marine));
    }
    if (marine.is_on_floor() && marine.input->is_action_just_pressed("ui_up")) {
        marine.state_machine.ChangeState(std::make_unique<godot::JumpState>(marine));
    }

}

void godot::IdleState::Exit() {
}
