//
// Created by albani on 10/9/26.
//

#ifndef REDOTCPPGAME_MARINE_H
#define REDOTCPPGAME_MARINE_H
#include <memory>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>


#include "StateMachine.h"
#include "IdleState.h"


namespace godot {
    class Marine : public CharacterBody2D{
        GDCLASS(Marine, CharacterBody2D);

    public:
        StateMachine state_machine;
        static void _bind_methods();

        Marine();
        ~Marine() override;

        void _ready() override;
        void _physics_process(double p_delta) override;
        void _exit_tree() override;

        float dir;
        Vector2 velocity = get_velocity();
        const float speed = 300.0f;
        const float gravity = 980.0f;
        const float JumpForce = -600.0f;
        Input *input = Input::get_singleton();
        float move_speed = 150.0f;

        AnimatedSprite2D *animated_sprite;
    };
}


#endif //REDOTCPPGAME_MARINE_H
