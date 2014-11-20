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
         Factory::camera->setCameraDirection( Factory::window->glWidget->getRobotController()->getRobotDestinationX(),5,Factory::window->glWidget->getRobotController()->getRobotDestinationZ());
    }
    else
    {
        // Viewpoint from outside the room
        //eyeZ = 80;

        // Viewpoint from inside the room
        //eyeZ = 40;
        Factory::camera->setEyePosition(0,0,60);
        Factory::camera->setCameraDirection( 0,0,0);
    }
}
