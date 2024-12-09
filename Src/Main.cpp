#include "raylib.h"
#include "MCmovement.h"
#include "Intro.h"

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1056;

    InitWindow(screenWidth, screenHeight, "Detective Game");

    GameScreen currentScreen = LOGO;

    int framesCounter = 0;          // Useful to count frames
    Font currentfont = LoadFont("resources/fonts/setback.png");
    Texture2D storyTeller = LoadTexture("Assets/Story/sidelook.png");
    Texture2D dialoguBubble = LoadTexture("Assets/Story/bubbledialog.png");
    bool showIntro = true;
    std::vector<std::string> dialogue = {
        "Welcome to the town of \nMistwood.",
        "You are a detective hired \nto solve a mysterious case.",
        "Find clues, question locals,\n and uncover the truth.",
        "Good luck, detective!"
    };
    int dialogueIndex = 0;

    bool gameStart = false;

    Character character;
    InitCharacter(character, { 400.0f, 300.0f });
    Texture2D background = LoadTexture("Assets/Level/bg.png");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        UpdateCharacter(character);
        ScreenLoader(currentScreen, framesCounter);

        BeginDrawing();

        ClearBackground(RAYWHITE);

       
        if(gameStart)
        {
            DrawTexture(background, 0,0, RAYWHITE);
            DrawCharacter(character);
        }
        else
        {
             DrawScreen(screenWidth, screenHeight, gameStart, dialogueIndex, dialogue, currentScreen, showIntro, currentfont, storyTeller, dialoguBubble, background);
        }
        

        EndDrawing();
    }

    UnloadCharacter(character);
    CloseWindow();

    return 0;
}
