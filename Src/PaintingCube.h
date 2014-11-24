#ifndef PAINTINGCUBE_H
#define PAINTINGCUBE_H

#include <cstdio>
#include "Node.h"

class PaintingCube: public ScenegraphNode
{
public:
    PaintingCube();
    void traverseNode();
private:

    void renderPaintingCube();
};

#endif // PAINTINGCUBE_H
