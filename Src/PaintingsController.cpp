#include "PaintingsController.h"

PaintingsController::PaintingsController()
{
    INTERPOLATION_MIN   = 0 ;
    INTERPOLATION_MAX   = 100;

    interpolVarHangingAnimation  = new QPropertyAnimation(this, "interpolVarHanging");
    interpolVarFallingAnimation  = new QPropertyAnimation(this, "interpolVarFalling");

    QObject::connect(this, SIGNAL(interpolVarHangingChanged(float)), this, SLOT(updatePaintingHangAngle()));
    QObject::connect(this, SIGNAL(interpolVarFallingChanged(float)), this, SLOT(updatePaintingFallAngle()));

    interpolVarHangingAnimation->setKeyValueAt(0,INTERPOLATION_MIN);
    interpolVarHangingAnimation->setKeyValueAt(.5,INTERPOLATION_MAX);
    interpolVarHangingAnimation->setKeyValueAt(1,INTERPOLATION_MIN);
    //interpolationVariableAnimation->setLoopCount(-1);
    interpolVarHangingAnimation->setEasingCurve(QEasingCurve::OutElastic);
    interpolVarHangingAnimation->setDuration(5000);

    interpolVarFallingAnimation->setKeyValueAt(0,INTERPOLATION_MIN);
    interpolVarFallingAnimation->setKeyValueAt(1,INTERPOLATION_MAX);
    interpolVarFallingAnimation->setEasingCurve(QEasingCurve::OutBounce);
    interpolVarFallingAnimation->setDuration(2000);
}

void PaintingsController::startPaintingHangingMotion()
{
    interpolVarHangingAnimation->stop();
    interpolVarHangingAnimation->start();
}

void PaintingsController::startPaintingFallingMotion()
{
    interpolVarFallingAnimation->stop();
    interpolVarFallingAnimation->start();
}

void PaintingsController::updatePaintingHangAngle()
{
    Factory::paintingTransformList[4]->setRotationTo( ((130-90)*m_interpolVarHanging)/100 + 90  ,Factory::paintingTransformList[4]->getRotationY(), Factory::paintingTransformList[4]->getRotationZ() );
    Factory::paintingTransformList[6]->setRotationTo( ((130-90)*m_interpolVarHanging)/100 + 90  ,Factory::paintingTransformList[6]->getRotationY(), Factory::paintingTransformList[6]->getRotationZ() );
    Factory::paintingTransformList[8]->setRotationTo( ((130-90)*m_interpolVarHanging)/100 + 90  ,Factory::paintingTransformList[8]->getRotationY(), Factory::paintingTransformList[8]->getRotationZ() );
}

void PaintingsController::updatePaintingFallAngle()
{
    Factory::paintingTransformList[0]->setRotationTo   (((90)*m_interpolVarFalling)/100 + 90 , Factory::paintingTransformList[0]->getRotationY(), Factory::paintingTransformList[0]->getRotationZ());
    Factory::paintingTransformList[0]->setTranslationTo(Factory::paintingTransformList[0]->getTranslationX() , ((-12)*m_interpolVarFalling)/100 - 12,((-20+30)*m_interpolVarFalling)/100 - 30 );

    Factory::paintingTransformList[1]->setRotationTo   (((90)*m_interpolVarFalling)/100 + 90 , Factory::paintingTransformList[1]->getRotationY(), Factory::paintingTransformList[1]->getRotationZ());
    Factory::paintingTransformList[1]->setTranslationTo(Factory::paintingTransformList[1]->getTranslationX() , ((-12)*m_interpolVarFalling)/100 - 12,((-20+30)*m_interpolVarFalling)/100 - 30 );

    Factory::paintingTransformList[2]->setRotationTo   (((90)*m_interpolVarFalling)/100 + 90 , Factory::paintingTransformList[2]->getRotationY(), Factory::paintingTransformList[2]->getRotationZ());
    Factory::paintingTransformList[2]->setTranslationTo(Factory::paintingTransformList[2]->getTranslationX() , ((-12)*m_interpolVarFalling)/100 - 12,((-20+30)*m_interpolVarFalling)/100 - 30 );
}
