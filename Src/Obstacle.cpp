#include "Obstacle.h"

Obstacle::Obstacle()
{
}

void Obstacle::traverseNode()
{
    renderobstacle();
}

void Obstacle::renderobstacle()
{
    glutSolidCube(10);
}
