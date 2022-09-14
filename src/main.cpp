#include <raylib-cpp.hpp>

#include "game/Game.hpp"

int main() {
    Game::Init();

    // Main game loop
    while (!Game::GetWindow().ShouldClose()) // Detect window close button or ESC key
    {
        Game::Update();
        BeginDrawing();
            Game::Draw();
        EndDrawing();
    }

    Game::Shutdown();
    return 0;
}