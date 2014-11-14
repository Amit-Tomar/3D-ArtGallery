#include "CustomRotatableTransform.h"

CustomRotatableTransform::CustomRotatableTransform()
{
}

void CustomRotatableTransform::applyTransformation()
{
    /*
         Actual order of applying these transforms is Scale-Rotate-Transfor.
         But because of being pushed into stack, they are passed on in reverse.
    */

    // Translate back to the desired position
    glTranslatef(getTranslationX(), getTranslationY(), getTranslationZ());

    glRotatef(getRotationX(), 1.0, 0.0, 0.0);
    glRotatef(getRotationY(), 0.0, 1.0, 0.0);
    glRotatef(getRotationZ(), 0.0, 0.0, 1.0);

    glScalef(getScaleX(),getScaleY(),getScaleZ());
    glColor3d(getColorR(), getColorG(),getColorB());

    // Translate to rotate about a given point
    glTranslatef(rotationPointX, rotationPointY, rotationPointZ);
}

void CustomRotatableTransform::setRotationPoint(float x, float y, float z)
{
    rotationPointX = x;
    rotationPointY = y;
    rotationPointZ = z;
}
