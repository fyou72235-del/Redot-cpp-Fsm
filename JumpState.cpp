//
// Created by albani on 10/10/26.
//

#include "JumpState.h"

#include "FallState.h"
#include "Marine.h"

godot::JumpState::JumpState(Marine &marine) : marine(marine){

}

godot::JumpState::~JumpState() {

}

void godot::JumpState::Enter() {
    UtilityFunctions::print("jump");
    marine.animated_sprite->play("Jump");
    marine.velocity.y = marine.JumpForce;
    marine.set_velocity(marine.velocity);
}

void godot::JumpState::Update(double delta) {
    ApplyGravity(delta);
    if (marine.velocity.y > 0) {
        marine.state_machine.ChangeState(std::make_unique<godot::FallState>(marine));
    }
    marine.velocity.x = marine.dir * marine.move_speed;
    marine.set_velocity(marine.velocity);
}

void godot::JumpState::Exit() {

}

void godot::JumpState::ApplyGravity(double delta) {
    if (!marine.is_on_floor()) {
        marine.velocity.y = marine.gravity * delta + marine.velocity.y;
        marine.set_velocity(marine.velocity);
    }
}
