#include "PaintingCube.h"

#define SPOT_DIRECTION  1
#define SPOT_CUTOFF     2
#define SPOT_EXPONENT   3
PaintingCube::PaintingCube()
{

}

void PaintingCube::traverseNode()
{
       renderPaintingCube();
}
void PaintingCube::renderPaintingCube()
{
    //painting placing board
    glPushMatrix();
    glColor3f(1,1,1);
    glScalef(1,-0.5,1);
    glTranslatef(-.01,0,-.01);
    glutSolidCube(1);
    glPopMatrix();
}
