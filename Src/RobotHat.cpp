#include "RobotHat.h"

RobotHat::RobotHat()
{

}

void RobotHat::traverseNode()
{
    renderHat();
}

void RobotHat::renderHat()
{
    glPushMatrix();
    glTranslatef(0.0,0.0f,2.5f);
    glRotatef(25.0,0.0,1.0,0.0);
    glutSolidCylinder(3,.5,50,50);
    glPopMatrix();
    glutSolidCylinder(1.2,4,50,50);
}
