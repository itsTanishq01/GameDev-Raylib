#ifndef COLLISIONPHYSICS_H
#define COLLISIONPHYSICS_H

#include "raylib.h"
#include "MCmovement.h"
#include "MapCollision.h" // Include the MapCollision header
#include <vector>

class CollisionPhysics {
public:
    static bool CheckCollision(const Character& character);
    static void HandleCollision(Character& character, Vector2 originalPosition);
};

#endif // COLLISIONPHYSICS_H
