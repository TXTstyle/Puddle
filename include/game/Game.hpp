#pragma once

#include <vector>
#include <Vector2.hpp>
#include <raylib-cpp.hpp>

#include "game/Ball.hpp"
#include "game/Player.hpp"

class Game
{
private:
    Game();
    static raylib::Vector2 screenSize;
    static raylib::Window window;
    static raylib::Color textColor;
    static raylib::Color boardColor;

    static std::vector<Ball> Balls;
    static Player player;
public:
    
    static void Init();
    static void Update();
    static void Draw();
    static void Shutdown();

    static inline raylib::Window& GetWindow() { return window; }
};