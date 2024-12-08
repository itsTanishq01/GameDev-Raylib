#include "raylib.h"

int main() {
    // Initialize the window
    const int screenWidth = 1600;
    const int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "2D Sprite Movement");

    // Define sprite properties
    Texture2D sprite = LoadTexture("resources/images.jpeg"); // Replace with your sprite path
    Vector2 position = {screenWidth / 2.0f, screenHeight / 2.0f}; // Start position
    float speed = 400.0f; // Movement speed in pixels per second

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if (IsKeyDown(KEY_W)) position.y -= speed * GetFrameTime(); // Move up
        if (IsKeyDown(KEY_S)) position.y += speed * GetFrameTime(); // Move down
        if (IsKeyDown(KEY_A)) position.x -= speed * GetFrameTime(); // Move left
        if (IsKeyDown(KEY_D)) position.x += speed * GetFrameTime(); // Move right

        // Render
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Use WASD to move the sprite!", 10, 10, 20, DARKGRAY);
        DrawTexture(sprite, static_cast<int>(position.x), static_cast<int>(position.y), WHITE);

        EndDrawing();
    }

    // Unload resources and close the window
    UnloadTexture(sprite);
    CloseWindow();

    return 0;
}
