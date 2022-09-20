#include "game/Player.hpp"


Player::Player()
: ball(Ball(pos)) { }

void Player::Update() {
    raylib::Vector2 pos3(raylib::Mouse::GetPosition()-ball.GetPos());

    if(holdShot == 1 && IsMouseButtonUp(MouseButton::MOUSE_BUTTON_LEFT)) {
        holdShot = false;
        ball.AddVel(-(pos3).Normalize()*power);
    }

    power = (pos3.Length())*0.1f;
    if(IsMouseButtonDown(MouseButton::MOUSE_BUTTON_LEFT) 
        && CheckCollisionPointCircle(raylib::Mouse::GetPosition(), ball.GetPos(), 25.0f)) {
        holdShot = true;
    }

    ball.Update();
}

void Player::Draw() {
    raylib::Mouse::GetPosition().DrawCircle(5.0f, raylib::Color(RED)); 
    //raylib::DrawText(std::to_string(holdShot), 10, 10, 10, raylib::Color(RED));

    if(holdShot) {
        ball.GetPos().DrawLine((raylib::Mouse::GetPosition()-ball.GetPos()).Normalize()*2.0f*power+ball.GetPos(), raylib::Color(WHITE));
        raylib::DrawText(std::to_string((int)power), 700, 100, 16, raylib::Color(WHITE));    
    }
    ball.Draw();
}
