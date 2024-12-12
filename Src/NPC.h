#ifndef NPC_H
#define NPC_H

#include "raylib.h"
#include "MCmovement.h"
#include <vector>
#include <string>

// Sprite sheet dimensions
#define SPRITE_WIDTH 64
#define SPRITE_HEIGHT 64

struct NPC {
    Texture2D spriteSheet;
    Texture2D dialogBox;
    Vector2 position;
    Rectangle collisionBox;
};

// Struct to hold all intro NPCs
struct IntroNpcResources
{
    std::vector<Vector2> startPositions;
    std::vector<std::string> spritePath;
    std::vector<std::string> dialogBoxPath;
};

// Function declarations
void InitNpcRsrc(IntroNpcResources &introNpcs);

// Initialize a list of NPCs
void InitNPCs(std::vector<NPC>& npcs,const std::vector<Vector2>& startPositions, std::vector<std::string>& spritePaths, std::vector<std::string>& dialogBoxPaths) ;
// Draw all NPCs
void DrawNPCs(std::vector<NPC> npcs);

// Check if the character is interacting with any NPC
bool IsInteractableWithAnyNPC(const std::vector<NPC>& npcs, Character& character, int& interactingNPCIndex);

// Display interaction prompt and dialog for the relevant NPC
void DisplayQuestion(const std::vector<NPC>& npcs, Character& character);

// Unload resources for all NPCs
void UnloadNPCs(std::vector<NPC>& npcs);


#endif // NPC_H
