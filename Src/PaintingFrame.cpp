#include "PaintingFrame.h"

#define SPOT_DIRECTION  1
#define SPOT_CUTOFF     2
#define SPOT_EXPONENT   3
PaintingFrame::PaintingFrame()
{

}

void PaintingFrame::traverseNode()
{
       renderPaintingCube();
}
void PaintingFrame::renderPaintingCube()
{
    //painting placing board
    glPushMatrix();
    glColor3f(.85,.85,.85);
    glScalef(1,-1,1);
    glTranslatef(-.01,0,-.01);
    glutSolidCube(1);
    glPopMatrix();
}
