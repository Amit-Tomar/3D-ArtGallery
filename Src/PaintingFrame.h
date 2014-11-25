#ifndef PAINTINGCUBE_H
#define PAINTINGCUBE_H

#include <cstdio>
#include "Node.h"

class PaintingFrame: public ScenegraphNode
{
public:
    PaintingFrame();
    void traverseNode();
private:

    void renderPaintingCube();
};

#endif // PAINTINGCUBE_H
