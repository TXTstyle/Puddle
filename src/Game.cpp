#include "game/Game.hpp"
#include <iostream>

raylib::Vector2 Game::screenSize(1280.0f, 720.0f);
raylib::Window Game::window(screenSize.x, screenSize.y, "Puddle");
raylib::Color Game::textColor(BLACK);
raylib::Color Game::boardColor(DARKGREEN);
std::vector<Ball> Game::Balls = std::vector<Ball>();
Player Game::player;

void Game::Init() {
    SetTargetFPS(60);

    //Balls.push_back(Ball(raylib::Vector2(700.0f, 200.0f)));
    Balls.push_back(Ball(raylib::Vector2(500.0f, 250.0f), 6.0f, raylib::Color(BLACK)));
    Balls[0].AddVel(5.0f, 5.0f);
    player.GetBall().AddVel(5.0f, 5.0f);
    //std::cout << Balls[0].vel.y << std::endl;
    
}

void Game::Update() {
    
    if(CheckCollisionCircles(player.GetBall().GetPos(), 6.0f, Balls[0].GetPos(), 6.0f)) {
        raylib::Vector2 bVec = player.GetBall().GetVel();
        raylib::Vector2 vec = player.GetBall().GetPos()-Balls[0].GetPos();
        Balls[0].AddPos(Balls[0].GetPos().Distance(player.GetBall().GetPos())*0.25f);
        Balls[0].AddVel(-vec*0.5f);
        //player.GetBall().AddVel(-(Balls[0].GetPos()-player.GetBall().GetPos()));
        player.GetBall().AddVel(-(-vec-player.GetBall().GetVel())*0.5f);
        player.GetBall().AddPos(-(Balls[0].GetPos().Distance(player.GetBall().GetPos()))*0.25f);
        if(bVec.Length() < player.GetBall().GetVel().Length())
            player.GetBall().SetLen(bVec.Length());
    }

    player.Update();
    for (auto &&ball : Balls)
    {
        ball.Update();
    }
}

void Game::Draw() {
    ClearBackground(BLUE);
    textColor.DrawText("Welcome to Puddle!", 256, 100, 32);
    
    boardColor.DrawRectangle(256, 144, 768, 432);

    player.Draw();

    for (auto &&ball : Balls)
    {
        ball.Draw();
    }
}

void Game::Shutdown() {
    std::cout << "Shutdown" << std::endl;
}
