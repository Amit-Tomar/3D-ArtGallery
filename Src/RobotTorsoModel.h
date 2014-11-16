#ifndef ROBOTTORSOMODEL_H
#define ROBOTTORSOMODEL_H

#include "Node.h"

class RobotTorsoModel: public ScenegraphNode
{
public:
    RobotTorsoModel();
    void traverseNode();

private:

    void renderTorso();
};

#endif // ROBOTTORSOMODEL_H
