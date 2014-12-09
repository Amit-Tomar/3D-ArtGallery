#ifndef ROBOTHAT_H
#define ROBOTHAT_H

#include "Node.h"

class RobotHat: public ScenegraphNode
{
public:
    RobotHat();
    void traverseNode();

private:

    void renderHat();
};

#endif // ROBOTHAT_H
