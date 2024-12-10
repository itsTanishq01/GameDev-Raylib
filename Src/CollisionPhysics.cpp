#include "CollisionPhysics.h"

bool CollisionPhysics::CheckCollision(const Character& character) {
    for (const auto& rect : mapRectangles) {
        if (CheckCollisionRecs(character.collisionBox, rect)) {
            return true;
        }
    }
    return false;
}

void CollisionPhysics::HandleCollision(Character& character, Vector2 originalPosition) {
    // Check for collision in the new position
    if (CheckCollision(character)) {
        // If collision detected, revert to original position
        character.position = originalPosition;
        character.collisionBox.x = originalPosition.x;
        character.collisionBox.y = originalPosition.y;
    }
}
