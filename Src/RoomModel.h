#ifndef ROOMMODEL_H
#define ROOMMODEL_H

#include "Node.h"

class RoomModel : public ScenegraphNode
{
public:
    RoomModel();
    void traverseNode();

private:

    void renderRoom();
};

#endif // ROOMMODEL_H
