#include "NPC.h"
#include "CollisionPhysics.h"
#include "MapCollision.h"
#include <vector>
#include <string>

// Function to initialize a vector of NPCs
void InitNPCs(std::vector<NPC>& npcs,const std::vector<Vector2>& startPositions, std::vector<std::string>& spritePaths, std::vector<std::string>& dialogBoxPaths) 
{
    for (int i = 0; i < startPositions.size(); ++i) 
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
    for(int i=1;i<=4;i++)
    {
        std::string image = "Assets/NpcSingle/npc" + std::to_string(i) + ".png";;
        introNpcResources.spritePath.push_back(image);
        std::string dialogbox = "Assets/NpcSingle/dialogbox" + std::to_string(i) + ".png";;
        introNpcResources.dialogBoxPath.push_back(dialogbox);
    }

}

// Function to draw all NPCs
void DrawNPCs(std::vector<NPC> npcs) 
{
    for (auto &npc:npcs) 
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
bool IsInteractableWithAnyNPC(const std::vector<NPC>& npcs, Character& character, int& interactingNPCIndex) {
    for (int i = 0; i < npcs.size(); ++i) {
        if (CheckCollisionRecs(npcs[i].collisionBox, character.collisionBox)) {
            interactingNPCIndex = static_cast<int>(i);
            return true;
        }
    }
    interactingNPCIndex = -1;
    return false;
}

// Function to display a question for the interacting NPC
void DisplayQuestion(const std::vector<NPC>& npcs, Character& character) {
    Font font = LoadFont("resources/fonts/setback.png");
    int interactingNPCIndex = -1;

    if (IsInteractableWithAnyNPC(npcs, character, interactingNPCIndex)) {
        DrawRectangle(70.0f, 1000.0f, 450, 50, GRAY);
        DrawTextEx(font, "PRESS E TO TALK", { 75.0f, 1005.0 }, 20, 5, WHITE);

        if (IsKeyDown(KEY_E)) 
        {
            if(interactingNPCIndex==0 || interactingNPCIndex==3)
            DrawTexture(npcs[interactingNPCIndex].dialogBox, (npcs[interactingNPCIndex].position.x + 40.0f), (npcs[interactingNPCIndex].position.y - 130.0f), WHITE);
            else
            DrawTexture(npcs[interactingNPCIndex].dialogBox, (npcs[interactingNPCIndex].position.x - 440.0f), (npcs[interactingNPCIndex].position.y - 130.0f), WHITE);        }
    }
}

// Function to unload all NPCs
void UnloadNPCs(std::vector<NPC>& npcs) {
    for (auto& npc : npcs) {
        UnloadTexture(npc.spriteSheet);
    }
    npcs.clear();
}
