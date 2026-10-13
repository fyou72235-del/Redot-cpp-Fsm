//
// Created by albani on 10/9/26.
//

#ifndef REDOTCPPGAME_PLAYERSTATE_H
#define REDOTCPPGAME_PLAYERSTATE_H
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/input.hpp>

namespace godot {
    class PlayerState{

    public:
        PlayerState();
        virtual ~PlayerState();

        virtual void Enter();
        virtual void Update(double delta);
        virtual void Exit();

    };
}


#endif //REDOTCPPGAME_PLAYERSTATE_H
