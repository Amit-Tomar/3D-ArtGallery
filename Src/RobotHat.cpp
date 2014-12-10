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
    glTranslatef(0.0,0.0f,3.0f);
    glRotatef(20.0,0.0,1.0,0.0);
    glutSolidCylinder(3,.5,50,50);
    glPopMatrix();
    glutSolidCylinder(1.3,4,50,50);
}
