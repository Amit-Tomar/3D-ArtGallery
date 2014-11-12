#include "RobotTorseModel.h"

RobotTorsoModel::RobotTorsoModel()
{
}

void RobotTorsoModel::traverseNode()
{
        renderTorso();
}

void RobotTorsoModel::renderTorso()
{
    glPushMatrix();
    glScalef(1,2,1);
    glutSolidCube(1);
    glPopMatrix();
}
