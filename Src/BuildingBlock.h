#ifndef BUILDINGBLOCK_H
#define BUILDINGBLOCK_H

#include <cstdio>
#include "Node.h"
#include <SOIL/SOIL.h>

struct Image
{
     long sizeX;
    unsigned long sizeY;
    char *data;
};

typedef struct Image Image;

class BuildingBlock: public ScenegraphNode
{
public:
    BuildingBlock(std::string, unsigned int = 1);
    void traverseNode();

private:

    void renderBuildingBlock();
    GLuint textureId;
    std::string textureImagePath;
    bool textureBinded;
    unsigned int textureRepeatNumber;
};

#endif // BUILDINGBLOCK_H
