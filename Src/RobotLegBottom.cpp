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
    glScalef(1,2.5,1);
    glutSolidCube(.35);
    glPopMatrix();
}
