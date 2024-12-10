#pragma once
#ifndef INTRO_H
#define INTRO_H

#include "raylib.h"
#include <vector>
#include <string>

// Enum for game screens
typedef enum GameScreen { LOGO = 0, TITLE, INTRO, ENDING } GameScreen;

// Struct to hold game state
struct GameState {
    int framesCounter;
    bool showIntro;
    int dialogueIndex;
    bool gameStart;
};

// Struct to hold all intro resources
struct IntroResources {
    GameScreen currentScreen;
    GameState gameState;
    Font currentfont;
    Texture2D storyTeller;
    Texture2D dialoguBubble;
    Texture2D background;
    std::vector<std::string> dialogue;
};

// Function declarations
void ScreenLoader(GameScreen& currentScreen, int& framesCounter);
void DrawScreen(const int screenWidth, const int screenHeight, GameState& gameState, std::vector<std::string>& dialogue, GameScreen& currentScreen, Font currentfont, Texture2D storyTeller, Texture2D dialoguBubble, Texture2D background);
void InitIntro(Font& currentfont, Texture2D& storyTeller, Texture2D& dialoguBubble, Texture2D& background, std::vector<std::string>& dialogue);
void UnloadIntro(Font& currentfont, Texture2D& storyTeller, Texture2D& dialoguBubble, Texture2D& background);
void InitGameState(GameState& gameState);

// New functions for resource management
void PrepareIntroResources(IntroResources& resources);
void UnloadIntroResources(IntroResources& resources);

#endif // INTRO_H