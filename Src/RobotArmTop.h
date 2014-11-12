#ifndef ROBOTARMTOP_H
#define ROBOTARMTOP_H

#include <Node.h>

class RobotArmTop : public ScenegraphNode
{
public:
    RobotArmTop();
    void traverseNode();

private:

    void renderArmTop();
};

#endif // ROBOTARMTOP_H
