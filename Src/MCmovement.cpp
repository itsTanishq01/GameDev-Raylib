#include "MCmovement.h"
#include "CollisionPhysics.h"
#include "MapCollision.h"

extern std::vector<Rectangle> mapRectangles; // Declare the map rectangles as an external variable

void InitCharacter(Character& character, Vector2 startPosition) {
    character.spriteSheets[0] = LoadTexture("Assets/Player/WSpriteSheet.png");
    character.spriteSheets[1] = LoadTexture("Assets/Player/ASpriteSheet.png");
    character.spriteSheets[2] = LoadTexture("Assets/Player/SSpriteSheet.png");
    character.spriteSheets[3] = LoadTexture("Assets/Player/DSpriteSheet.png");
    character.currentFrame = 0;
    character.currentDirection = 0;
    character.animationTimer = 0.0f;
    character.position = startPosition;
    character.collisionBox = { startPosition.x, startPosition.y, SPRITE_WIDTH, SPRITE_HEIGHT };
}

void UpdateCharacter(Character& character) {
    Vector2 originalPosition = character.position;
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

    // Handle collision
    CollisionPhysics::HandleCollision(character, originalPosition);
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

    //Draw collision box(for debugging purposes)
    DrawRectangleLines(
        static_cast<int>(character.collisionBox.x),
        static_cast<int>(character.collisionBox.y),
        static_cast<int>(character.collisionBox.width),
        static_cast<int>(character.collisionBox.height),
        RED
    );
}

void UnloadCharacter(Character& character) {
    for (int i = 0; i < 4; i++) {
        UnloadTexture(character.spriteSheets[i]);
    }
}
