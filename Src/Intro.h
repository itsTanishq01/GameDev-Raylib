#pragma once
#ifndef INTRO_H
#define INTRO_H

#include "raylib.h"
#include <vector>
#include <string>

// Enum for game screens
typedef enum GameScreen { LOGO = 0, TITLE, INTRO, ENDING } GameScreen;

// Function declarations
void ScreenLoader(GameScreen &currentScreen, int &framesCounter);
void DrawScreen(const int screenWidth, const int screenHeight, bool &gameStart,int& dialogueIndex, std::vector<std::string>& dialogue, GameScreen& currentScreen, bool& showIntro, Font currentfont, Texture2D storyTeller, Texture2D dialoguBubble,Texture2D background);
#endif // INTRO_H
