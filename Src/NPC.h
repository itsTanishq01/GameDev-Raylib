#ifndef NPC_H
#define NPC_H

#include "raylib.h"
#include "MCmovement.h"

// Sprite sheet dimensions
#define SPRITE_WIDTH 64
#define SPRITE_HEIGHT 64

struct NPC {
    Texture2D spriteSheet;
    Texture2D dialogBox;
    Vector2 position;
    Rectangle collisionBox;
};

void InitNPC(NPC& npc, Vector2 startPosition);
void DrawNPC(const NPC& npc);
bool IsInteractable(const NPC& npc,const Character& character);
void DisplayQuestion(const NPC &npc,const Character& character);
void UnloadNPC(NPC& npc);

#endif // NPC_H
