#include "CameraController.h"

CameraController::CameraController()
{
    cameraFollowingRobot = false ;
}

void CameraController::repositionCamera()
{
    if( cameraFollowingRobot )
    {
         Factory::camera->setEyePosition(Factory::robotTorsoTransform->getTranslationX(), Factory::robotTorsoTransform->getTranslationY(), Factory::robotTorsoTransform->getTranslationZ());
         Factory::camera->setCameraDirection( Factory::window->glWidget->getRobotController()->getRobotDestinationX(),Factory::window->glWidget->getRobotController()->getRobotDestinationY(),Factory::window->glWidget->getRobotController()->getRobotDestinationZ());
    }
    else
    {
        Factory::camera->setEyePosition(0,0,45);
        Factory::camera->setCameraDirection( 0,0,0);
    }
}
