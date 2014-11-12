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
    glutSolidCube(1);
}
