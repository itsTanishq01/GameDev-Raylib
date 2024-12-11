#pragma once

#ifndef INPUT
#define INPUT


#include "raylib.h"
#include <string.h>
#include <iostream>
#include <vector>

struct InputResources {
    std::string inputData;
    bool mouseOnText;
    int framesCounter;
    Texture2D dialogueBubble;
    Rectangle textBox;
    bool DrawAnswer;

};
void InitIntro(std::string& inputData, bool& mouseOnText, int& framesCounter, Texture2D& dialogueBubble, Rectangle& textBox);
void PrepareIntroResources(InputResources& resources);
void UpdateFrame(InputResources& resources);
void UnloadDialogBox(InputResources& resources);
#endif


