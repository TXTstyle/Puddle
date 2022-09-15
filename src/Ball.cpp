#include "game/Ball.hpp"

#include <iostream>


Ball::~Ball() {
    
}

Ball::Ball(raylib::Vector2 p_pos, float p_radie, raylib::Color p_color)
: pos(p_pos), radie(p_radie), color(p_color) { }

Ball::Ball(raylib::Vector2 p_pos)
: pos(p_pos), radie(6.0f), color(raylib::Color(WHITE)) { }

void Ball::Draw() {
    pos.DrawCircle(radie, color);
}

void Ball::Update() {
    pos += vel;

    if(pos.x >= 1024-radie) {
        vel.x *= -1;
        vel *= 1-fric*2;
        pos.x = 1024-radie;
    }
    if(pos.x <= 256+radie) {
        vel.x *= -1;
        vel *= 1-fric*2;
        pos.x = 256+radie;
    }
    if(pos.y <= 144+radie) {
        vel.y *= -1;
        vel *= 1-fric*2;
        pos.y = 144+radie;
    }
    if(pos.y >= 576-radie) {
        vel.y *= -1;
        vel *= 1-fric*2;
        pos.y = 576-radie;
    }

    vel *= 1-fric;
}