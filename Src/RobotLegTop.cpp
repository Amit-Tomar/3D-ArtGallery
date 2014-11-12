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
    glScalef(1,2.5,1);
    glutSolidCube(.35);
    glPopMatrix();
}
