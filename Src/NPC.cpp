#include "NPC.h"
#include "CollisionPhysics.h"
#include "MapCollision.h"
#include <vector>
#include <string>

// Function to initialize a vector of NPCs
void InitNPCs(std::vector<NPC>& npcs, const std::vector<Vector2>& startPositions, const std::vector<std::string>& spritePaths, const std::vector<std::string>& dialogBoxPaths)
{
    npcs.reserve(startPositions.size());
    for (size_t i = 0; i < startPositions.size(); ++i)
    {
        NPC npc;
        npc.spriteSheet = LoadTexture(spritePaths[i].c_str());
        npc.dialogBox = LoadTexture(dialogBoxPaths[i].c_str());
        npc.position = startPositions[i];
        npc.collisionBox = { startPositions[i].x, startPositions[i].y, SPRITE_WIDTH, SPRITE_HEIGHT };
        npcs.push_back(npc);
    }
}

void InitNpcRsrc(IntroNpcResources& introNpcResources)
{
    introNpcResources.startPositions = {
        {90.0f , 200.0f},
        {1800.0f , 315.0f},
        {1815.0f , 870.0f},
        {60.0f , 730.0f}
    };

    introNpcResources.spritePath.reserve(4);
    introNpcResources.dialogBoxPath.reserve(4);

    for (int i = 1; i <= 4; ++i)
    {
        introNpcResources.spritePath.emplace_back("Assets/NpcSingle/npc" + std::to_string(i) + ".png");
        introNpcResources.dialogBoxPath.emplace_back("Assets/NpcSingle/dialogbox" + std::to_string(i) + ".png");
    }
}

// Function to draw all NPCs
void DrawNPCs(const std::vector<NPC>& npcs)
{
    for (const auto& npc : npcs)
    {
        DrawTextureV(npc.spriteSheet, npc.position, WHITE);

        /* Draw collision box (for debugging purposes)
        DrawRectangleLines(
            static_cast<int>(npc.collisionBox.x),
            static_cast<int>(npc.collisionBox.y),
            static_cast<int>(npc.collisionBox.width),
            static_cast<int>(npc.collisionBox.height),
            BLACK
        );*/
    }
}

// Function to check interaction with any NPC
bool IsInteractableWithAnyNPC(const std::vector<NPC>& npcs, const Character& character, int& interactingNPCIndex) {
    for (size_t i = 0; i < npcs.size(); ++i) {
        if (CheckCollisionRecs(npcs[i].collisionBox, character.collisionBox)) {
            interactingNPCIndex = static_cast<int>(i);
            return true;
        }
    }
    interactingNPCIndex = -1;
    return false;
}

// Function to display a question for the interacting NPC
void DisplayQuestion(const std::vector<NPC>& npcs, const Character& character, Font& font) {
    static bool showDialog = false;
    static int interactingNPCIndex = -1;

    if (IsInteractableWithAnyNPC(npcs, character, interactingNPCIndex)) {
        DrawRectangle(70.0f, 1000.0f, 450, 50, GRAY);
        DrawTextEx(font, "Press E to talk", { 75.0f, 1005.0f }, 20, 5, WHITE);

        if (IsKeyPressed(KEY_E)) {
            showDialog = !showDialog;
        }

        if (showDialog) {
            if (interactingNPCIndex == 0 || interactingNPCIndex == 3)
                DrawTexture(npcs[interactingNPCIndex].dialogBox, (npcs[interactingNPCIndex].position.x + 40.0f), (npcs[interactingNPCIndex].position.y - 130.0f), WHITE);
            else
                DrawTexture(npcs[interactingNPCIndex].dialogBox, (npcs[interactingNPCIndex].position.x - 440.0f), (npcs[interactingNPCIndex].position.y - 130.0f), WHITE);
        }
    }
    else {
        showDialog = false;
    }
}

// Function to unload all NPCs
void UnloadNPCs(std::vector<NPC>& npcs) {
    for (auto& npc : npcs) {
        UnloadTexture(npc.spriteSheet);
        UnloadTexture(npc.dialogBox);
    }
    npcs.clear();
}
