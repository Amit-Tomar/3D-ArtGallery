#ifndef ROBOTSHOE_H
#define ROBOTSHOE_H

#include <Node.h>

class RobotShoe : public ScenegraphNode
{
public:
    RobotShoe();
    void traverseNode();

private:

    void renderShoe();
};

#endif // ROBOTSHOE_H
