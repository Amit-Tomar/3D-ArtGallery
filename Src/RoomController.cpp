#include "RoomController.h"

RoomController::RoomController()
{
    interpolationVariableAnimation  = new QPropertyAnimation(this, "interpolationVariable");
    QObject::connect(this, SIGNAL(interpolationVariableChanged(float)), this, SLOT(updateBackWallPosition()));

    INTERPOLATION_MIN = 0 ;
    INTERPOLATION_MAX = 100;
}

void RoomController::moveBackWall()
{
    interpolationVariableAnimation->setDuration(5000);
    interpolationVariableAnimation->setKeyValueAt(0,INTERPOLATION_MIN);
    interpolationVariableAnimation->setKeyValueAt(1,INTERPOLATION_MAX);
    interpolationVariableAnimation->setEasingCurve(QEasingCurve::OutBounce);
    interpolationVariableAnimation->start();
}


void RoomController::updateBackWallPosition()
{
    Factory::roomBackWallTransform->setTranslationTo(Factory::roomBackWallTransform->getTranslationX(),Factory::roomBackWallTransform->getTranslationY(), (((-70+40)*m_interpolationVariable)/100) - 40 );
}

