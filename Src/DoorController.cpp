#include "DoorController.h"

DoorController::DoorController()
{
    interpolationVariableAnimation  = new QPropertyAnimation(this, "interpolationVariable");
    QObject::connect(this, SIGNAL(interpolationVariableChanged(float)), this, SLOT(updateDoorPositions()));

    INTERPOLATION_MIN = 0 ;
    INTERPOLATION_MAX = 100;
}

void DoorController::openDoor()
{
    interpolationVariableAnimation->setDuration(5000);
    interpolationVariableAnimation->setKeyValueAt(0,INTERPOLATION_MIN);
    interpolationVariableAnimation->setKeyValueAt(1,INTERPOLATION_MAX);
    interpolationVariableAnimation->start();
    Factory::audioPlayer->playDoorSound();
}

void DoorController::closeDoor()
{
    Factory::roomFrontWallRightDoorTransform->setTranslationTo(28.5,-5,65);
    Factory::roomFrontWallRightDoorTransform->setRotationTo(90,0,0);

    Factory::roomFrontWallLeftDoorTransform->setTranslationTo(18,-5,65);
    Factory::roomFrontWallLeftDoorTransform->setRotationTo(90,0,0);
}

void DoorController::updateDoorPositions()
{
    Factory::roomFrontWallLeftDoorTransform->setRotationTo( Factory::roomFrontWallLeftDoorTransform->getRotationX() ,Factory::roomFrontWallLeftDoorTransform->getRotationY(), ((84)*m_interpolationVariable)/100);
    Factory::roomFrontWallLeftDoorTransform->setTranslationTo((((14-17)*m_interpolationVariable)/100) + 17, Factory::roomFrontWallLeftDoorTransform->getTranslationY(),Factory::roomFrontWallLeftDoorTransform->getTranslationZ() );

    Factory::roomFrontWallRightDoorTransform->setRotationTo( Factory::roomFrontWallRightDoorTransform->getRotationX() ,Factory::roomFrontWallRightDoorTransform->getRotationY(), ((-30)*m_interpolationVariable)/100 );
    Factory::roomFrontWallRightDoorTransform->setTranslationTo( (((32.5-28.5)*m_interpolationVariable)/100) + 28.5, Factory::roomFrontWallRightDoorTransform->getTranslationY(),Factory::roomFrontWallRightDoorTransform->getTranslationZ() );
}
