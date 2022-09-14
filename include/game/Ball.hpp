#pragma once
#include <raylib-cpp.hpp>

class Ball
{
private:
    float radie;
    float fric = 0.05f;
    raylib::Color color;
    raylib::Vector2 pos;
    raylib::Vector2 dir = raylib::Vector2(1, 1);
    raylib::Vector2 vel = raylib::Vector2(0, 0);
public:
    Ball(raylib::Vector2 p_pos, float p_radie, raylib::Color p_color);
    Ball(raylib::Vector2 p_pos);
    ~Ball();

    void Draw();
    void Update();

    inline raylib::Vector2 GetPos() { return pos; }
    
    inline void AddVel(raylib::Vector2 p_vel) { vel += p_vel; }
    inline void AddVel(float x, float y) { vel += raylib::Vector2(x, y); }
};