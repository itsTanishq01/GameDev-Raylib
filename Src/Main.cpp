#include "raylib.h"
#include "MCmovement.h"
#include "Intro.h"

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1056;

    InitWindow(screenWidth, screenHeight, "Detective Game");

    GameScreen currentScreen = LOGO;
    int framesCounter = 0;
    bool showIntro = true;
    int dialogueIndex = 0;
    bool gameStart = false;

    Font currentfont;
    Texture2D storyTeller;
    Texture2D dialoguBubble;
    Texture2D background;
    std::vector<std::string> dialogue;

    InitIntro(currentfont, storyTeller, dialoguBubble, background, dialogue);

    Character character;
    InitCharacter(character, { 400.0f, 300.0f });

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        UpdateCharacter(character);
        ScreenLoader(currentScreen, framesCounter);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (gameStart)
        {
            DrawTexture(background, 0, 0, RAYWHITE);
            DrawCharacter(character);
        }
        else
        {
            DrawScreen(screenWidth, screenHeight, gameStart, dialogueIndex, dialogue,
                currentScreen, showIntro, currentfont, storyTeller, dialoguBubble, background);
        }

        EndDrawing();
    }

    UnloadCharacter(character);
    UnloadIntro(currentfont, storyTeller, dialoguBubble, background);
    CloseWindow();

    return 0;
}
