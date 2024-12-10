#ifndef MAPCOLLISION_H
#define MAPCOLLISION_H

#include "raylib.h"
#include <vector>

struct CollisionRectangle {
    int x1, y1, x2, y2;
};

class MapCollision {
public:
    void drawRectangles();
private:
    std::vector<CollisionRectangle> rectangles;
};

extern std::vector<Rectangle> mapRectangles;

#endif // MAPCOLLISION_H
