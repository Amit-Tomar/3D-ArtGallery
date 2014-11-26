#ifndef TEAPOT_H
#define TEAPOT_H

#include "Node.h"

class Teapot : public ScenegraphNode
{
public:
    Teapot();
    void traverseNode();

private:

    void renderTeapot();
};

#endif // TEAPOT_H
