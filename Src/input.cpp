#include "input.h"
#include <string.h>

void InitInput(std::string& inputData, bool& mouseOnText, int& framesCounter, Texture2D& dialogueBubble, Rectangle& textBox) {
    inputData = "";
    mouseOnText = false;
    textBox = { 1000,9500, 225, 50 };
    dialogueBubble = LoadTexture("../Assets/Story/testInp.png");
    framesCounter = 0;
    
    
}
void UpdatePositionParameters(Vector2 position,InputResources &resources){

}
void UpdateFrame(InputResources& resources,Vector2 position,int NpcNumber) {

    
    resources.textBox = { position.x + 70,position.y + 95, 225, 50 };
    resources.position = position;
    if (CheckCollisionPointRec(GetMousePosition(), resources.textBox))
        resources.mouseOnText = true;
    else
        resources.mouseOnText = false;

    if (resources.mouseOnText)
    {
        // Set the window's cursor to the I-Beam

        SetMouseCursor(MOUSE_CURSOR_IBEAM);

        // Get char pressed (unicode character) on the queue
        int key = GetCharPressed();

        // Check if more characters have been pressed on the same frame
        while (key > 0)
        {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125) && (resources.inputData.length() < 9))
            {
                resources.inputData += static_cast<char>(key);
            }

            key = GetCharPressed();  // Check next character in the queue
        }

        if (IsKeyPressed(KEY_BACKSPACE) && !resources.inputData.empty())
        {
            resources.inputData.pop_back();
        }
    }
    else
    {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

    if (resources.mouseOnText) {
        resources.framesCounter++;
    }
    else {
        resources.framesCounter = 0;
    }

    DrawTexture(resources.dialogueBubble, position.x ,position.y, WHITE);
    //DrawTexture(resources.dialogueBubble, 80,180, LIGHTGRAY);40, 40, 43
    //DrawRectangleRec(resources.textBox,(Color){ 200, 200, 200, 50 });
    DrawRectangleRec(resources.textBox,(Color){ 40, 40, 40, 255 });
    if (resources.mouseOnText) {
        DrawRectangleLines((int)resources.textBox.x, (int)resources.textBox.y, (int)resources.textBox.width, (int)resources.textBox.height, RED);
    }
    else {
        DrawRectangleLines((int)resources.textBox.x, (int)resources.textBox.y, (int)resources.textBox.width, (int)resources.textBox.height, DARKGRAY);
    }
    DrawText(resources.inputData.c_str(), (int)resources.textBox.x + 5, (int)resources.textBox.y + 8, 40, WHITE);

    //DrawText(TextFormat("INPUT CHARS: %i/%i", (int)resources.inputData.length(), 9), 315, 250, 20, DARKGRAY);

    if (resources.mouseOnText)
    {
        if (resources.inputData.length() < 9)
        {
            // Draw blinking underscore char
            if (((resources.framesCounter / 20) % 2) == 0)
                DrawText("_", (int)resources.textBox.x + 8 + MeasureText(resources.inputData.c_str(), 40), (int)resources.textBox.y + 12, 40, MAROON);
        }
        // else
        // {
        //     DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
        // }
    }
    if (IsKeyPressed(KEY_ENTER)) {
        
        
        if(resources.inputData == resources.answers[NpcNumber]){
            resources.DrawAnswer = true;
            std::cout << resources.inputData;
        }

    }
    if (resources.DrawAnswer) {
        //DrawText(TextFormat(" %s", resources.inputData.c_str()), position.x + 60,position.y + 160, 2, WHITE);
        DrawText("Correct!! Go To Next NPC", position.x + 55,position.y + 200, 28, WHITE);
        //resources.DrawAnswer = false;
    }
}
void PrepareInputResources(InputResources& resources)
{   

    //Fix This We cant We assigning Answers in random function

    resources.answers[0] = "one";
    resources.answers[1] = "two";
    resources.answers[2] = "three";
    resources.answers[3] = "four";


    resources.DrawAnswer = false;
    InitInput(resources.inputData, resources.mouseOnText, resources.framesCounter, resources.dialogueBubble, resources.textBox);
}
void UnloadDialogBox(InputResources& resources) {
    UnloadTexture(resources.dialogueBubble);
}



