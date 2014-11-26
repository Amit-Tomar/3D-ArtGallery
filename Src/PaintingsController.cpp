#include "PaintingsController.h"

PaintingsController::PaintingsController()
{
    INTERPOLATION_MIN   = 0 ;
    INTERPOLATION_MAX   = 100;

    interpolationVariableAnimation  = new QPropertyAnimation(this, "interpolationVariable");

    QObject::connect(this, SIGNAL(interpolationVariableChanged(float)), this, SLOT(updatePaintingAngle()));

    interpolationVariableAnimation->setKeyValueAt(0,INTERPOLATION_MIN);
    interpolationVariableAnimation->setKeyValueAt(.5,INTERPOLATION_MAX);
    interpolationVariableAnimation->setKeyValueAt(1,INTERPOLATION_MIN);
    //interpolationVariableAnimation->setLoopCount(-1);
    interpolationVariableAnimation->setEasingCurve(QEasingCurve::OutElastic);
    interpolationVariableAnimation->setDuration(5000);
}

void PaintingsController::startPaintingMotion()
{
    interpolationVariableAnimation->stop();
    interpolationVariableAnimation->start();
}

void PaintingsController::updatePaintingAngle()
{
    Factory::painting5Transform->setRotationTo( ((130-90)*m_interpolationVariable)/100 + 90  ,Factory::painting5Transform->getRotationY(), Factory::painting5Transform->getRotationZ() );
}
