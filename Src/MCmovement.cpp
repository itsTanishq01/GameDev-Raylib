#include "MCmovement.h"

void InitCharacter(Character& character, Vector2 startPosition) {
    character.spriteSheets[0] = LoadTexture("Assets/WSpriteSheet.png");
    character.spriteSheets[1] = LoadTexture("Assets/ASpriteSheet.png");
    character.spriteSheets[2] = LoadTexture("Assets/SSpriteSheet.png");
    character.spriteSheets[3] = LoadTexture("Assets/DSpriteSheet.png");
    character.currentFrame = 0;
    character.currentDirection = 0;
    character.animationTimer = 0.0f;
    character.position = startPosition;
    character.collisionBox = { startPosition.x, startPosition.y, SPRITE_WIDTH, SPRITE_HEIGHT };
}

void UpdateCharacter(Character& character) {
    bool isMoving = false;
    if (IsKeyDown(KEY_W)) {
        character.currentDirection = 0;
        character.position.y -= 200 * GetFrameTime();
        isMoving = true;
    }
    else if (IsKeyDown(KEY_A)) {
        character.currentDirection = 1;
        character.position.x -= 200 * GetFrameTime();
        isMoving = true;
    }
    else if (IsKeyDown(KEY_S)) {
        character.currentDirection = 2;
        character.position.y += 200 * GetFrameTime();
        isMoving = true;
    }
    else if (IsKeyDown(KEY_D)) {
        character.currentDirection = 3;
        character.position.x += 200 * GetFrameTime();
        isMoving = true;
    }

    if (isMoving) {
        character.animationTimer += GetFrameTime();
        if (character.animationTimer >= 0.1f) {
            character.currentFrame = (character.currentFrame + 1) % SPRITE_COLUMNS;
            character.animationTimer = 0.0f;
        }
    }
    else {
        character.currentFrame = 0;
    }

    character.collisionBox.x = character.position.x;
    character.collisionBox.y = character.position.y;
}

void DrawCharacter(const Character& character) {
    Texture2D currentSpriteSheet = character.spriteSheets[character.currentDirection];
    Rectangle sourceRec = {
        (float)character.currentFrame * SPRITE_WIDTH,
        0.0f,
        SPRITE_WIDTH,
        SPRITE_HEIGHT
    };
    Rectangle destRec = {
        character.position.x,
        character.position.y,
        SPRITE_WIDTH,
        SPRITE_HEIGHT
    };
    Vector2 origin = { 0.0f, 0.0f };
    DrawTexturePro(currentSpriteSheet, sourceRec, destRec, origin, 0.0f, WHITE);

    // Draw collision box (for debugging purposes)
    DrawRectangleLines(
        character.collisionBox.x,
        character.collisionBox.y,
        character.collisionBox.width,
        character.collisionBox.height,
        RED
    );
}

void UnloadCharacter(Character& character) {
    for (int i = 0; i < 4; i++) {
        UnloadTexture(character.spriteSheets[i]);
    }
}
