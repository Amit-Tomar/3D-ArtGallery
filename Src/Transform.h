#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QTimer>
#include <iostream>
#include <cmath>
#include "Node.h"
#include "TransformTypes.h"

class Transform:  public QObject, public ScenegraphNode
{
    Q_OBJECT

public:
    Transform();
    ~Transform();

    void traverseNode();
    void interpolateRotationTo(float,float,float,unsigned int=0);
    void interpolateTranslationTo(float,float,float,unsigned int=0);
    void interpolateScaleTo(float,float,float,unsigned int=0);
    void setColor(double,double,double);

    float getRotationX(){ return currentRotation.x; }
    float getRotationY(){ return currentRotation.y; }
    float getRotationZ(){ return currentRotation.z; }
    float getScaleX(){ return currentScale.x; }
    float getScaleY(){ return currentScale.y; }
    float getScaleZ(){ return currentScale.z; }
    float getTranslationX(){ return currentTranslation.x; }
    float getTranslationY(){ return currentTranslation.y; }
    float getTranslationZ(){ return currentTranslation.z; }
    float getColorR(){ return red; }
    float getColorG(){ return green; }
    float getColorB(){ return blue; }

    void stopRotation();
    void stopTranslation();

private slots :

    void incrementXRotation();
    void incrementYRotation();
    void incrementZRotation();

    void decrementXRotation();
    void decrementYRotation();
    void decrementZRotation();

    void incrementXTranslation();
    void incrementYTranslation();
    void incrementZTranslation();

    void decrementXTranslation();
    void decrementYTranslation();
    void decrementZTranslation();
    virtual void applyTransformation();

private:

    Rotation currentRotation;
    Translation currentTranslation;
    Scale currentScale;

    Rotation rotationIncrement;
    Translation translationIncrement;

    Rotation finalRotationValue;
    Translation finalTranslationValue;

    QTimer *timer1RotationIncrement;
    QTimer *timer2RotationIncrement;
    QTimer *timer3RotationIncrement;

    QTimer *timer1RotationDecrement;
    QTimer *timer2RotationDecrement;
    QTimer *timer3RotationDecrement;

    QTimer *timer1TranslationIncrement;
    QTimer *timer2TranslationIncrement;
    QTimer *timer3TranslationIncrement;

    QTimer *timer1TranslationDecrement;
    QTimer *timer2TranslationDecrement;
    QTimer *timer3TranslationDecrement;

    double red,green,blue;
};

#endif // TRANSFORM_H
