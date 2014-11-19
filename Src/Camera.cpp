#include "Camera.h"

Camera::Camera()
{
    eyeX = 0;
    eyeY = 0;
    eyeZ = 45;
    directionX = 0;
    directionY = 0;
    directionZ = 0;
    upX = 0;
    upY = 1;
    upZ = 0;
}

void Camera::traverseNode()
{
    rePositionCamera();
}

void Camera::rePositionCamera()
{
    gluLookAt(eyeX,eyeY,eyeZ,directionX,directionY,directionZ,upX,upY,upZ);
}

void Camera::setEyePosition(float x, float y, float z)
{
    eyeX = x;
    eyeY = y;
    eyeZ = z;
}

void Camera::setCameraDirection(float x, float y, float z)
{
    directionX = x;
    directionY = y;
    directionZ = z;
}
