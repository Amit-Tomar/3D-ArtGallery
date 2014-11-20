#ifndef CAMERA_H
#define CAMERA_H
#include "Node.h"

#include "FactoryData.h"

class Camera : public ScenegraphNode
{
public:
    Camera();
    void traverseNode();
    void rePositionCamera();
    void setEyePosition(float,float,float);
    void setCameraDirection(float,float,float);

    float eyeX, eyeY, eyeZ, directionX, directionY, directionZ, upX, upY, upZ;

private:

//    float eyeX, eyeY, eyeZ, directionX, directionY, directionZ, upX, upY, upZ;
};

#endif // CAMERA_H
