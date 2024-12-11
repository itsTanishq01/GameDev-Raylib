#include "Intro.h"

void ScreenLoader(GameScreen& currentScreen, int& framesCounter)
{
    switch (currentScreen)
    {
    case LOGO:
    {
        framesCounter++; // Count frames
        if (framesCounter > 120)
        {
            currentScreen = TITLE;
        }
    } break;

    case TITLE:
    {
        if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        {
            currentScreen = INTRO;
        }
    } break;

    case INTRO:
    {
        if (IsKeyPressed(KEY_X))
        {
            currentScreen = ENDING;
        }
    } break;

    case ENDING:
    {
        if (IsKeyPressed(KEY_X))
        {
            currentScreen = TITLE;
        }
    } break;

    default: break;
    }
}

void DrawScreen(const int screenWidth, const int screenHeight, GameState& gameState, std::vector<std::string>& dialogue, GameScreen& currentScreen, Font currentfont, Texture2D storyTeller, Texture2D dialoguBubble, Texture2D background)
{
    if (gameState.showIntro && IsKeyPressed(KEY_SPACE)) {
        gameState.dialogueIndex++;
        if (gameState.dialogueIndex >= dialogue.size())
        {
            gameState.showIntro = false; // End intro dialogue
            gameState.gameStart = true;
        }
    }

    switch (currentScreen)
    {
    case LOGO:
    {
        DrawTextEx(currentfont, "LOGO SCREEN", { 550.0, 300.0 }, 120, 10, LIGHTGRAY);
        DrawTextEx(currentfont, "WAIT for 2 SECONDS...", { 800, 800 }, 25, 3, GRAY);
    } break;

    case TITLE:
    {
        DrawRectangle(0, 0, screenWidth, screenHeight, SKYBLUE);
        DrawTextEx(currentfont, "Detective Game", { 475.0, 300.0 }, 130, 10, BLACK);
        DrawTextEx(currentfont, "PRESS ENTER to GAMEPLAY SCREEN", { 500, 800 }, 30, 5, DARKGREEN);
    } break;

    case INTRO:
    {
        DrawTexture(background, 0, 0, RAYWHITE);

        // Step 2: Draw a semi-transparent rectangle over the background
        DrawTexturePro(
            background,
            Rectangle{ 0, 0, (float)background.width, (float)background.height },
            Rectangle{ 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() },
            Vector2{ 0, 0 }, 0.0f, Fade(WHITE, 0.8f) // Slight transparency for frosted effect
        );

        // Step 3: Draw a frosted glass overlay (white semi-transparent)
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{ 255, 255, 255, 150 }); // White with low alpha

        if (gameState.showIntro)
        {
            DrawTexture(storyTeller, -20, 500, WHITE);
            DrawTexture(dialoguBubble, 400, 700, WHITE);
            DrawText(dialogue[gameState.dialogueIndex].c_str(), 525, 785, 40, WHITE);
        }
    } break;

    case ENDING:
    {
        DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
        DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
        DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
    } break;

    default: break;
    }
}

void InitIntro(Font& currentfont, Texture2D& storyTeller, Texture2D& dialoguBubble, Texture2D& background, std::vector<std::string>& dialogue)
{
    currentfont = LoadFont("resources/fonts/setback.png");
    storyTeller = LoadTexture("Assets/Story/sidelook.png");
    dialoguBubble = LoadTexture("Assets/Story/bubbledialog.png");
    background = LoadTexture("Assets/Level/bg.png");
    dialogue = {
        "Welcome to the town of \n Mistwood.",
        "You are a detective hired \n to solve a mysterious case.",
        "Find clues, question locals,\n and uncover the truth.",
        "Good luck, detective!"
    };
}

void UnloadIntro(Font& currentfont, Texture2D& storyTeller, Texture2D& dialoguBubble, Texture2D& background)
{
    UnloadFont(currentfont);
    UnloadTexture(storyTeller);
    UnloadTexture(dialoguBubble);
    UnloadTexture(background);
}

void InitGameState(GameState& gameState)
{
    gameState.framesCounter = 0;
    gameState.showIntro = true;
    gameState.dialogueIndex = 0;
    gameState.gameStart = false;
}

// New function to prepare resources
void PrepareIntroResources(IntroResources& resources)
{
    resources.currentScreen = LOGO;
    InitGameState(resources.gameState);
    InitIntro(resources.currentfont, resources.storyTeller,
        resources.dialoguBubble, resources.background,
        resources.dialogue);
}

// New function to unload resources
void UnloadIntroResources(IntroResources& resources)
{
    UnloadIntro(resources.currentfont, resources.storyTeller,
        resources.dialoguBubble, resources.background);
}