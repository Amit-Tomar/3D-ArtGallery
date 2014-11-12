#ifndef ROBOTHEAD_H
#define ROBOTHEAD_H

#include "Node.h"

class RobotHead : public ScenegraphNode
{
public:
    RobotHead();
    void traverseNode();

private:

    void renderRobotHead();
};

#endif // ROBOTHEAD_H
