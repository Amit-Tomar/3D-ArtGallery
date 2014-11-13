#include "RobotLegBottom.h"

RobotLegBottom::RobotLegBottom()
{
}

void RobotLegBottom::traverseNode()
{
    renderRobotLegBottom();
}

void RobotLegBottom::renderRobotLegBottom()
{
    glPushMatrix();
    glScalef(1,3,1);
    glutSolidCube(.35);
    glPopMatrix();
}
