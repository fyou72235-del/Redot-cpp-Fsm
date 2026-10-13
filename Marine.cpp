//
// Created by albani on 10/9/26.
//

#include "Marine.h"

namespace godot {
    void Marine::_bind_methods() {
    }

    Marine::Marine() {
    }

    Marine::~Marine() {
    }

    void Marine::_ready() {
        animated_sprite = get_node<AnimatedSprite2D>("AnimatedSprite2D");
        state_machine.ChangeState(std::make_unique<IdleState>(*this));
    }

    void Marine::_physics_process(double p_delta) {
        if (Engine::get_singleton()->is_editor_hint()) {
            return;
        }
        dir = input->get_axis("ui_left",
            "ui_right");
        state_machine.UpdateState(p_delta);

        if (velocity.x < 0) {
            animated_sprite->set_flip_h(true);
        }
        if (velocity.x > 0) {
            animated_sprite->set_flip_h(false);
        }

        move_and_slide();
    }


    void Marine::_exit_tree() {

    }
}
