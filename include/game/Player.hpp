#pragma once
#include <game/Ball.hpp>

class Player
{
private:
    bool holdShot = false;
    raylib::Vector2 pos = raylib::Vector2(500.0f, 200.0f);
    Ball ball;
public:
    Player();

    float power = 0.0f;
    
    void Update();
    void Draw();

    inline Ball& GetBall() { return ball; }
};