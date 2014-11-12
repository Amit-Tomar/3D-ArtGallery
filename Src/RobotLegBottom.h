#ifndef ROBOTLEGBOTTOM_H
#define ROBOTLEGBOTTOM_H

#include <Node.h>

class RobotLegBottom: public ScenegraphNode
{
public:
    RobotLegBottom();
    void traverseNode();

private:

    void renderRobotLegBottom();
};

#endif // ROBOTLEGBOTTOM_H
