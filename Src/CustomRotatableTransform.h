#ifndef CUSTOMROTATABLETRANSFORM_H
#define CUSTOMROTATABLETRANSFORM_H

#include "Transform.h"

class CustomRotatableTransform: public Transform
{
public:
    CustomRotatableTransform();
    void applyTransformation();
    void setRotationPoint(float,float,float);

private:

    float rotationPointX;
    float rotationPointY;
    float rotationPointZ;
};

#endif // CUSTOMROTATABLETRANSFORM_H
