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
    Vector2 position;
    std::string answers[4];
};
void InitInput(std::string& inputData, bool& mouseOnText, int& framesCounter, Texture2D& dialogueBubble, Rectangle& textBox,Vector2 position);
void PrepareInputResources(InputResources& resources);
void UpdateFrame(InputResources& resources,Vector2 position,int NpcNumber);
void UnloadDialogBox(InputResources& resources);
void UpdatePositionParameters(Vector2 position,InputResources &resources);
#endif


