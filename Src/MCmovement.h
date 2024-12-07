#ifndef MCMOVEMENT_H
#define MCMOVEMENT_H

#include "raylib.h"

// Sprite sheet dimensions
#define SPRITE_WIDTH 64
#define SPRITE_HEIGHT 64
#define SPRITE_COLUMNS 9

struct Character {
    Texture2D spriteSheets[4];
    int currentFrame;
    int currentDirection;
    float animationTimer;
    Vector2 position;
};

void InitCharacter(Character& character, Vector2 startPosition);
void UpdateCharacter(Character& character);
void DrawCharacter(const Character& character);
void UnloadCharacter(Character& character);

#endif // MCMOVEMENT_H
