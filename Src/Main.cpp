#include "raylib.h"
#include "MCmovement.h"

int main() {
    InitWindow(1920 , 1056, "Running Animation");

    Character character;
    InitCharacter(character, { 400.0f, 300.0f });
    Texture2D background = LoadTexture("Assets/Level/bg.png");
    while (!WindowShouldClose()) {
        UpdateCharacter(character);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(background, 0,0, RAYWHITE);
        DrawCharacter(character);

        EndDrawing();
    }

    UnloadCharacter(character);
    CloseWindow();

    return 0;
}
