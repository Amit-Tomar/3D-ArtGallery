#ifndef obstacle_H
#define obstacle_H

#include "Node.h"

class Obstacle : public ScenegraphNode
{
public:
    Obstacle();
    void traverseNode();

private:

    void renderobstacle();
};

#endif // obstacle_H
