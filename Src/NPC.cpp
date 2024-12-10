#include "NPC.h"
#include "CollisionPhysics.h"
#include "MapCollision.h"
#include<iostream>

void InitNPC(NPC& npc, Vector2 startPosition) {
    npc.spriteSheet = LoadTexture("Assets/NpcSingle/startgirl.png");
    npc.dialogBox = LoadTexture("Assets/NpcSingle/dialogboxgirl.png");
    npc.position = startPosition;
    npc.collisionBox = { startPosition.x, startPosition.y, SPRITE_WIDTH, SPRITE_HEIGHT };
}

void DrawNPC(const NPC& npc) {
    DrawTextureV(npc.spriteSheet, npc.position , WHITE);

    /*Draw collision box(for debugging purposes)
    DrawRectangleLines(
        static_cast<int>(npc.collisionBox.x),
        static_cast<int>(npc.collisionBox.y),
        static_cast<int>(npc.collisionBox.width),
        static_cast<int>(npc.collisionBox.height),
        RED
    );*/
}

bool IsInteractable(const NPC &npc,const Character& character)
{
    if(CheckCollisionRecs(npc.collisionBox,character.collisionBox))
        return true;
    else 
        return false;
}

void DisplayQuestion(const NPC &npc,const Character& character)
{
    Font font = LoadFont("resources/fonts/setback.png");
    if(IsInteractable(npc,character))
    {
        DrawRectangle(70.0f,1000.0f,450,50,GRAY);
        DrawTextEx(font , "PRESS E TO TALK" , { 75.0f , 1005.0 } , 20 , 5 , WHITE);
        if(IsKeyDown(KEY_E))
        {
            DrawTexture( npc.dialogBox , 130.0f , 70.0f , WHITE ); 
        }
    } 
}

void UnloadNPC(NPC& npc) {
    UnloadTexture(npc.spriteSheet);
}
