#include "RobotArmTop.h"

RobotArmTop::RobotArmTop()
{
}

void RobotArmTop::traverseNode()
{
    renderArmTop();
}

void RobotArmTop::renderArmTop()
{
    glutSolidCylinder(.20,1,100,100);
}
