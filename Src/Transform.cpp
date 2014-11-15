#include "Transform.h"

Transform::Transform(): ScenegraphNode(true)
{
    currentRotation.x = 0.0 ;
    currentRotation.y = 0.0 ;
    currentRotation.z = 0.0 ;

    currentTranslation.x = 0.0 ;
    currentTranslation.y = 0.0 ;
    currentTranslation.z = 0.0 ;

    currentScale.x = 1.0 ;
    currentScale.y = 1.0 ;
    currentScale.z = 1.0 ;

    rotationPointX = 0.0;
    rotationPointY = 0.0;
    rotationPointZ = 0.0;
}

Transform::~Transform()
{

}

void Transform::traverseNode()
{
    applyTransformation();
}

void Transform::setRotationTo(float xRot, float yRot, float zRot)
{
        currentRotation.x = xRot ;
        currentRotation.y = yRot ;
        currentRotation.z = zRot ;
}

void Transform::setTranslationTo(float xTrans, float yTrans, float zTrans)
{
    currentTranslation.x = xTrans ;
    currentTranslation.y = yTrans ;
    currentTranslation.z = zTrans ;
}

void Transform::setScaleTo(float xSc, float ySc, float zSc)
{
    currentScale.x = xSc;
    currentScale.y = ySc;
    currentScale.z = zSc;
}

void Transform::setColor(double r, double g, double b)
{
    red = r;
    green = g ;
    blue = b ;
}

void Transform::applyTransformation()
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

void Transform::setRotationPoint(float x, float y, float z)
{
    rotationPointX = x;
    rotationPointY = y;
    rotationPointZ = z;
}

