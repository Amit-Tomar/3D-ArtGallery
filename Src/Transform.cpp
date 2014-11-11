#include "Transform.h"

Transform::Transform()
{
    currentRotation.x = 0 ;
    currentRotation.y = 0 ;
    currentRotation.z = 0 ;

    currentTranslation.x = 0 ;
    currentTranslation.y = 0 ;
    currentTranslation.z = 0 ;

    currentScale.x = 1 ;
    currentScale.y = 1 ;
    currentScale.z = 1 ;

    rotationIncrement.x = 1.5 ;
    rotationIncrement.y = 1.5 ;
    rotationIncrement.z = 1.5 ;

    translationIncrement.x = 0.02 ;
    translationIncrement.y = 0.02 ;
    translationIncrement.z = 0.02 ;

    timer1RotationIncrement = new QTimer(NULL);
    connect(timer1RotationIncrement, SIGNAL(timeout()), this, SLOT(updateXRotationIncrement()));

    timer2RotationIncrement = new QTimer(NULL);
    connect(timer2RotationIncrement, SIGNAL(timeout()), this, SLOT(updateYRotationIncrement()));

    timer3RotationIncrement = new QTimer(NULL);
    connect(timer3RotationIncrement, SIGNAL(timeout()), this, SLOT(updateZRotationIncrement()));

    timer1RotationDecrement = new QTimer(NULL);
    connect(timer1RotationDecrement, SIGNAL(timeout()), this, SLOT(updateXRotationDecrement()));

    timer2RotationDecrement = new QTimer(NULL);
    connect(timer2RotationDecrement, SIGNAL(timeout()), this, SLOT(updateYRotationDecrement()));

    timer3RotationDecrement = new QTimer(NULL);
    connect(timer3RotationDecrement, SIGNAL(timeout()), this, SLOT(updateZRotationDecrement()));

    //

    timer1TranslationIncrement = new QTimer(NULL);
    connect(timer1TranslationIncrement, SIGNAL(timeout()), this, SLOT(updateXTranslationIncrement()));

    timer2TranslationIncrement = new QTimer(NULL);
    connect(timer2TranslationIncrement, SIGNAL(timeout()), this, SLOT(updateYTranslationIncrement()));

    timer3TranslationIncrement = new QTimer(NULL);
    connect(timer3TranslationIncrement, SIGNAL(timeout()), this, SLOT(updateZTranslationIncrement()));

    timer1TranslationDecrement = new QTimer(NULL);
    connect(timer1TranslationDecrement, SIGNAL(timeout()), this, SLOT(updateXTranslationDecrement()));

    timer2TranslationDecrement = new QTimer(NULL);
    connect(timer2TranslationDecrement, SIGNAL(timeout()), this, SLOT(updateYTranslationDecrement()));

    timer3TranslationDecrement = new QTimer(NULL);
    connect(timer3TranslationDecrement, SIGNAL(timeout()), this, SLOT(updateZTranslationDecrement()));
}

Transform::~Transform()
{

}

void Transform::traverseNode()
{
    // std::cout << "Traversed Node : Transform" << std::endl ;
    applyTransformation();
}

void Transform::interpolateRotationTo(float xRot, float yRot, float zRot, unsigned int time)
{
    if( 0 == time )
    {
        currentRotation.x = xRot ;
        currentRotation.y = yRot ;
        currentRotation.z = zRot ;
    }

    else
    {
        finalRotationValue.x = (int)xRot%360 ;
        finalRotationValue.y = (int)yRot%360 ;
        finalRotationValue.z = (int)zRot%360 ;

        if( finalRotationValue.x >  currentRotation.x )
            timer1RotationIncrement->start(10);
        else
            timer1RotationDecrement->start(10);

        if( finalRotationValue.y >  currentRotation.y )
            timer2RotationIncrement->start(10);
        else
            timer2RotationDecrement->start(10);

        if( finalRotationValue.z >  currentRotation.z )
            timer3RotationIncrement->start(10);
        else
            timer3RotationDecrement->start(10);
    }
}

void Transform::interpolateTranslationTo(float xTrans, float yTrans, float zTrans, unsigned int time)
{
    if( 0 == time )
    {
        currentTranslation.x = xTrans ;
        currentTranslation.y = yTrans ;
        currentTranslation.z = zTrans ;
    }

    else
    {
        finalTranslationValue.x = xTrans ;
        finalTranslationValue.y = yTrans ;
        finalTranslationValue.z = zTrans ;

        if( finalTranslationValue.x >  currentTranslation.x )
            timer1TranslationIncrement->start(100);
        else
            timer1TranslationDecrement->start(100);

        if( finalTranslationValue.y >  currentTranslation.y )
            timer2TranslationIncrement->start(100);
        else
            timer2TranslationDecrement->start(100);

        if( finalTranslationValue.z >  currentTranslation.z )
            timer3TranslationIncrement->start(100);
        else
            timer3TranslationDecrement->start(100);
    }
}

void Transform::interpolateScaleTo(float xSc, float ySc, float zSc, unsigned int time)
{
    currentScale.x = xSc;
    currentScale.y = ySc;
    currentScale.z = zSc;
}

void Transform::setColor(double r, double g, double b)
{
    std::cout << " red" << r << " " << g << " " << b << std::endl ;
    red = r;
    green = g ;
    blue = b ;
}

void Transform::stopRotation()
{
    timer1RotationDecrement->stop();
    timer1RotationIncrement->stop();
    timer2RotationDecrement->stop();
    timer2RotationIncrement->stop();
    timer3RotationDecrement->stop();
    timer3RotationIncrement->stop();
}

void Transform::stopTranslation()
{
    timer1TranslationDecrement->stop();
    timer1TranslationIncrement->stop();
    timer2TranslationDecrement->stop();
    timer2TranslationIncrement->stop();
    timer3TranslationDecrement->stop();
    timer3TranslationIncrement->stop();
}

void Transform::updateXRotationIncrement()
{
    std::cout << "Here" << std::endl ;
    if( currentRotation.x < finalRotationValue.x )
    {
        currentRotation.x += rotationIncrement.x ;
    }
    else
    {
        timer1RotationIncrement->stop();
    }
}

void Transform::updateYRotationIncrement()
{
    if( currentRotation.y < finalRotationValue.y )
        currentRotation.y += rotationIncrement.y ;
    else
        timer2RotationIncrement->stop();
}

void Transform::updateZRotationIncrement()
{
    if( currentRotation.z < finalRotationValue.z )
        currentRotation.z += rotationIncrement.z ;
    else
        timer3RotationIncrement->stop();
}

//

void Transform::updateXRotationDecrement()
{
    std::cout << "Here Dec" << std::endl ;
    if( currentRotation.x > finalRotationValue.x )
    {
        currentRotation.x -= rotationIncrement.x ;
    }
    else
    {
        timer1RotationDecrement->stop();
    }
}

void Transform::updateYRotationDecrement()
{
    if( currentRotation.y > finalRotationValue.y )
        currentRotation.y -= rotationIncrement.y ;
    else
        timer2RotationDecrement->stop();
}

void Transform::updateZRotationDecrement()
{
    if( currentRotation.z > finalRotationValue.z )
        currentRotation.z -= rotationIncrement.z ;
    else
        timer3RotationDecrement->stop();
}

void Transform::updateXTranslationIncrement()
{
    if( currentTranslation.x < finalTranslationValue.x )
    {
        currentTranslation.x += translationIncrement.x ;
    }
    else
    {
        timer1TranslationIncrement->stop();
    }
}

void Transform::updateYTranslationIncrement()
{
    if( currentTranslation.y < finalTranslationValue.y )
    {
        currentTranslation.y += translationIncrement.y ;
    }
    else
    {
        timer2TranslationIncrement->stop();
    }
}

void Transform::updateZTranslationIncrement()
{
    if( currentTranslation.z < finalTranslationValue.z )
    {
        currentTranslation.z += translationIncrement.z ;
    }
    else
    {
        timer3TranslationIncrement->stop();
    }
}

void Transform::updateXTranslationDecrement()
{
    if( currentTranslation.x > finalTranslationValue.x )
    {
        currentTranslation.x -= translationIncrement.x ;
    }
    else
    {
        timer1TranslationDecrement->stop();
    }
}

void Transform::updateYTranslationDecrement()
{
    if( currentTranslation.y > finalTranslationValue.y )
    {
        currentTranslation.y -= translationIncrement.y ;
    }
    else
    {
        timer2TranslationDecrement->stop();
    }
}

void Transform::updateZTranslationDecrement()
{
    if( currentTranslation.z > finalTranslationValue.z )
    {
        currentTranslation.z -= translationIncrement.z ;
    }
    else
    {
        timer3TranslationDecrement->stop();
    }
}

void Transform::applyTransformation()
{
    glPushMatrix();

    glTranslatef(currentTranslation.x,currentTranslation.y,currentTranslation.z);

    glRotatef(currentRotation.x, 1.0, 0.0, 0.0);
    glRotatef(currentRotation.y, 0.0, 1.0, 0.0);
    glRotatef(currentRotation.z, 0.0, 0.0, 1.0);

    glScalef(currentScale.x,currentScale.y,currentScale.z);
    glColor3d(red,green,blue);
}
