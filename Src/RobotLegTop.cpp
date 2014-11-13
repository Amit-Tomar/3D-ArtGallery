#include "RobotLegTop.h"

RobotLegTop::RobotLegTop()
{
}

void RobotLegTop::traverseNode()
{
    renderRobotLegTop();
}

void RobotLegTop::renderRobotLegTop()
{
    glPushMatrix();
    glScalef(1,3,1);
    glutSolidCube(.35);
    glPopMatrix();
}
