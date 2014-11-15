#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <qobject.h>
#include <QTimer>
#include <iostream>
#include <cmath>
#include "Node.h"
#include "TransformTypes.h"
#include <FactoryData.h>

class ScenegraphNode;

class Transform:  public QObject, public ScenegraphNode
{
    Q_OBJECT

public:
    Transform();
    ~Transform();

    void traverseNode();
    void setRotationTo(float,float,float);
    void setTranslationTo(float,float,float);
    void setScaleTo(float,float,float);
    void setColor(double,double,double);

    void  setRotationPoint(float,float,float);
    float getRotationX(){ return currentRotation.x; }
    float getRotationY(){ return currentRotation.y; }
    float getRotationZ(){ return currentRotation.z; }
    float getScaleX(){ return currentScale.x; }
    float getScaleY(){ return currentScale.y; }
    float getScaleZ(){ return currentScale.z; }
    float getTranslationX(){ return currentTranslation.x; }
    float getTranslationY(){ return currentTranslation.y; }
    float getTranslationZ(){ return currentTranslation.z; }
    float getColorR(){ return red;   }
    float getColorG(){ return green; }
    float getColorB(){ return blue;  }

private slots :

    virtual void applyTransformation();

private:

    Rotation currentRotation;
    Translation currentTranslation;
    Scale currentScale;

    double red,green,blue;

    // Rotation will happen about these point
    float rotationPointX;
    float rotationPointY;
    float rotationPointZ;
};

#endif // TRANSFORM_H
