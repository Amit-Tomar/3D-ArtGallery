#ifndef BUILDINGBLOCK_H
#define BUILDINGBLOCK_H

#include <cstdio>
#include "Node.h"

struct Image
{
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};

typedef struct Image Image;

class BuildingBlock: public ScenegraphNode
{
public:
    BuildingBlock(std::string = "");
    void traverseNode();

private:

    void renderBuildingBlock();
    GLuint textureId;
    std::string textureImagePath;
    Image * image;
    int loadImage();
    bool textureBinded;
};

#endif // BUILDINGBLOCK_H
