#ifndef ROBOTLEGTOP_H
#define ROBOTLEGTOP_H

#include <Node.h>

class RobotLegTop : public ScenegraphNode
{
public:
    RobotLegTop();
    void traverseNode();

private:

    void renderRobotLegTop();
};

#endif // ROBOTLEGTOP_H
