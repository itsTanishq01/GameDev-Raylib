#include "raylib.h"

void DrawSprite(int x, int y);
int main() {
    int screenWidth = 800;
    int screenHeight = 450;
    float MoveSpeed = 3.0f;
    int Position[2] = {screenWidth/2,screenHeight/2}; //2d Array for Sprite Position
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
 
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        //Using WASD movement
        if (IsKeyDown(KEY_D)) Position[0] += GetFrameTime() + MoveSpeed;
        if (IsKeyDown(KEY_A)) Position[0] -= GetFrameTime() + MoveSpeed;
        if (IsKeyDown(KEY_W)) Position[1] -= GetFrameTime() + MoveSpeed;
        if (IsKeyDown(KEY_S)) Position[1] += GetFrameTime() + MoveSpeed;


        BeginDrawing();
    
        ClearBackground(RAYWHITE);

        //Checking Bounds For Screen
        if(Position[1] > screenHeight -50){
            Position[1] = screenHeight- 50;
        }else if(Position[1] < 0 ){
            Position[1] = 0;
        }else if(Position[0] > screenWidth - 50){
            Position[0] = screenWidth - 50;
        }else if(Position[0] < 0){
            Position[0] = 0;
        }
        DrawSprite(Position[0],Position[1]);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
void DrawSprite(int x, int y){
    //For Now We Draw A circle
    DrawCircle(x,y,10,RED);
}