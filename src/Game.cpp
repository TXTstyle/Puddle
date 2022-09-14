#include "game/Game.hpp"
#include <iostream>

raylib::Vector2 Game::screenSize(1280.0f, 720.0f);
raylib::Window Game::window(screenSize.x, screenSize.y, "Puddle");
raylib::Color Game::textColor(BLACK);
raylib::Color Game::boardColor(DARKGREEN);
std::vector<Ball> Game::Balls = std::vector<Ball>();

void Game::Init() {
    SetTargetFPS(60);

    Balls.push_back(Ball(raylib::Vector2(500.0f, 200.0f)));
    //Balls.push_back(Ball(raylib::Vector2(500.0f, 250.0f), 8.0f, raylib::Color(BLACK)));
    Balls[0].AddVel(5.0f, 5.0f);
    //std::cout << Balls[0].vel.y << std::endl;
    
}

void Game::Update() {
    raylib::Vector2 pos3(raylib::Mouse::GetPosition()-Balls[0].GetPos());
    pos3 = raylib::Vector2(std::abs(pos3.x), std::abs(pos3.y));
    float len = (pos3.Length())*0.1f;
    if(IsKeyPressed(KEY_SPACE))
            Balls[0].AddVel((pos3).Normalize()*len);
    for (auto &&ball : Balls)
    {
        ball.Update();
    }
}

void Game::Draw() {
    ClearBackground(BLUE);
    textColor.DrawText("Welcome to Puddle!", 256, 100, 32);
    
    boardColor.DrawRectangle(256, 144, 768, 432);

    raylib::Mouse::GetPosition().DrawCircle(5.0f, raylib::Color(RED)); 
    
    float len = ((raylib::Mouse::GetPosition()-Balls[0].GetPos()).Length())*0.1f;
    Balls[0].GetPos().DrawLine((raylib::Mouse::GetPosition()-Balls[0].GetPos()).Normalize()*len+Balls[0].GetPos(), raylib::Color(WHITE));

    for (auto &&ball : Balls)
    {
        ball.Draw();
    }
    
}

void Game::Shutdown() {
    std::cout << "Shutdown" << std::endl;
}
