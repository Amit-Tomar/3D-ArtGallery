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
    interpolVarFallingAnimation->setDuration(5000);
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
    Factory::painting5Transform->setRotationTo( ((130-90)*m_interpolVarHanging)/100 + 90  ,Factory::painting5Transform->getRotationY(), Factory::painting5Transform->getRotationZ() );
}

void PaintingsController::updatePaintingFallAngle()
{
    Factory::painting4Transform->setRotationTo( Factory::painting4Transform->getRotationX(), ((90)*m_interpolVarFalling)/100 + 0 , Factory::painting4Transform->getRotationZ() );
    Factory::painting4Transform->setTranslationTo( ((30-45)*m_interpolVarFalling)/100 + 45 ,((-23)*m_interpolVarFalling)/100, Factory::painting4Transform->getTranslationZ() );
}
