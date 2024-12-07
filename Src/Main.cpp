#include "raylib.h"
#include "MCmovement.h"

int main() {
    InitWindow(800, 600, "Running Animation");

    Character character;
    InitCharacter(character, { 400.0f, 300.0f });

    while (!WindowShouldClose()) {
        UpdateCharacter(character);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCharacter(character);

        EndDrawing();
    }

    UnloadCharacter(character);
    CloseWindow();

    return 0;
}
