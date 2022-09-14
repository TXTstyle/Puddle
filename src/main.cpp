#include <raylib-cpp.hpp>

int main() {
    
    // Initialization
    int screenWidth = 800;
    int screenHeight = 450;

    raylib::Color textColor(BLACK);
    raylib::Window w(screenWidth, screenHeight, "Puddle");
    
    SetTargetFPS(60);

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        // TODO: Update your variables here

        // Draw
        BeginDrawing();
        ClearBackground(BLUE);
        textColor.DrawText("Welcome to Puddle!", 190, 200, 20);
        EndDrawing();
    }

    return 0;
}