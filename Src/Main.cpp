#include "raylib.h"
#include "MCmovement.h"
#include "Intro.h"
#include "input.h"
#include "MapCollision.h"
#include "CollisionPhysics.h" // Include the CollisionPhysics header


int main() {
    bool isTrue = false;
    const int screenWidth = 1920;
    const int screenHeight = 1056;

    InitWindow(screenWidth, screenHeight, "Detective Game");

    IntroResources introResources;
    PrepareIntroResources(introResources);

    InputResources inpResource;
    PrepareIntroResources(inpResource);

    Character character;
    InitCharacter(character, { 400.0f, 300.0f });

    MapCollision mapCollision;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        UpdateCharacter(character);
        ScreenLoader(introResources.currentScreen, introResources.gameState.framesCounter);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (introResources.gameState.gameStart) {
            DrawTexture(introResources.background, 0, 0, RAYWHITE);
            DrawCharacter(character);
            mapCollision.drawRectangles(); // Draw the rectangles
        }
        else {
            DrawScreen(screenWidth, screenHeight, introResources.gameState,
                introResources.dialogue, introResources.currentScreen,
                introResources.currentfont, introResources.storyTeller,
                introResources.dialoguBubble, introResources.background);
        }
        if (IsKeyPressed(KEY_X)) {
            isTrue = true;
        }
        if (isTrue) {
            UpdateFrame(inpResource);
        }
        EndDrawing();
    }

    UnloadCharacter(character);
    UnloadIntroResources(introResources);
    UnloadDialogBox(inpResource);
    CloseWindow();

    return 0;
}
