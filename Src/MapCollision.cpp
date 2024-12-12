#include "MapCollision.h"
#include "raylib.h"

// Define the map rectangles
std::vector<Rectangle> mapRectangles = {
    {0, 0, 865, 75},     // Rectangle 1
    {0, 75, 65, 305},    // Rectangle 2
    {0, 385, 865, 60},   // Rectangle 3
    {800, 295, 65, 150}, // Rectangle 4
    {800, 75, 65, 100},  // Rectangle 5
    {1055, 0, 865, 65},  // Rectangle 6
    {1055, 65, 55, 100}, // Rectangle 7
    {1055, 285, 55, 100},// Rectangle 8
    {1055, 385, 865, 60},// Rectangle 9
    {1880, 65, 40, 320}, // Rectangle 10
    {0, 610, 865, 55},   // Rectangle 11
    {0, 990, 865, 60},   // Rectangle 12
    {0, 665, 45, 325},   // Rectangle 13
    {800, 670, 65, 95},  // Rectangle 14
    {800, 860, 65, 130}, // Rectangle 15
    {1055, 610, 865, 60},// Rectangle 16
    {1055, 990, 865, 65},// Rectangle 17
    {1880, 675, 40, 315},// Rectangle 18
    {1050, 675, 35, 90}, // Rectangle 19
    {1050, 860, 35, 130},// Rectangle 20
    {865, 0, 190, 1},    // Rectangle 21
    {0, 445, 1, 165},           // Rectangle 22
    {865, 1055, 185, 1},        // Rectangle 23
    {1919, 449, 1, 161},        // Rectangle 24
    {95, 205, 45, 45},          //Girl
    {1810.0f , 325.0f,45, 45},  //easy
    {1825.0f , 880.0f, 45, 45}, //medium
    {60.0f , 740.0f, 45, 45}    //hard
};

void MapCollision::drawRectangles() {
    /*Draw the collision rectangles.Uncomment to see
    for (const auto& rect : mapRectangles) {
        DrawRectangleLines(static_cast<int>(rect.x), static_cast<int>(rect.y), static_cast<int>(rect.width), static_cast<int>(rect.height), RED); // Draw outline
    }
    */    
}
