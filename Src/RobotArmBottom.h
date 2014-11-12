#ifndef ROBOTARMBOTTOM_H
#define ROBOTARMBOTTOM_H

#include <Node.h>

class RobotArmBottom : public ScenegraphNode
{
public:
    RobotArmBottom();
    void traverseNode();

private:

    void renderRobotArmBottom();
};

#endif // ROBOTARMBOTTOM_H
