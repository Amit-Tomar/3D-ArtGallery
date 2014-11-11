#ifndef CAMERA_H
#define CAMERA_H
#include "Node.h"

class Camera : ScenegraphNode
{
public:
    Camera();
    void traverseNode();
};

#endif // CAMERA_H
