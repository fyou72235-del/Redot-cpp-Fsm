//
// Created by albani on 10/10/26.
//

#include "FallState.h"

#include "Marine.h"
#include "RunState.h"

godot::FallState::FallState(Marine &marine) : marine(marine)  {

}

godot::FallState::~FallState() {
}

void godot::FallState::Enter() {
    UtilityFunctions::print("fall");
    marine.animated_sprite->play("Fall");
}

void godot::FallState::Update(double delta) {
    marine.velocity.y = marine.gravity * delta + marine.velocity.y;
    marine.set_velocity(marine.velocity);

    if (marine.is_on_floor() && marine.dir == 0) {
        marine.state_machine.ChangeState(std::make_unique<godot::IdleState>(marine));
    }
    if (marine.is_on_floor() && marine.dir != 0) {
        marine.state_machine.ChangeState(std::make_unique<godot::RunState>(marine));
    }
    marine.velocity.x = marine.dir * marine.move_speed;
    marine.set_velocity(marine.velocity);
}

void godot::FallState::Exit() {

}
