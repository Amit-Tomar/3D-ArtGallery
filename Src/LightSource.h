#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "Node.h"

class LightSource : ScenegraphNode
{
public:
    LightSource();
    void traverseNode();
};

#endif // LIGHTSOURCE_H
