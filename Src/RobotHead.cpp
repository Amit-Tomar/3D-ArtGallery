#include "RobotHead.h"

RobotHead::RobotHead()
{
}

void RobotHead::traverseNode()
{
    renderRobotHead();
}

void RobotHead::renderRobotHead()
{
    glutSolidSphere(.40,100,100);
}
