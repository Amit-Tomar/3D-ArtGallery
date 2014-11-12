#include "RobotArmBottom.h"

RobotArmBottom::RobotArmBottom()
{
}

void RobotArmBottom::traverseNode()
{
    renderRobotArmBottom();
}

void RobotArmBottom::renderRobotArmBottom()
{
    glutSolidCylinder(.20,1.0,100,100);
}
