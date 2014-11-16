#include "RobotShoe.h"

RobotShoe::RobotShoe()
{
}

void RobotShoe::traverseNode()
{
    renderShoe();
}

void RobotShoe::renderShoe()
{
    glPushMatrix();
    glScalef(1,2,1);
    glutSolidCube(.35);
    glPopMatrix();
}
