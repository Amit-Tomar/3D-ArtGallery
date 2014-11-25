#include "CameraController.h"

CameraController::CameraController()
{
    cameraFollowingRobot = false ;

    Point p;
    p.x = 0.0;
    p.y = 0.0;
    p.z = 60.0;

    pointOfViewList.push_back(p);

    p.x = 0.0;
    p.y = 0.0;
    p.z = 110.0;

    pointOfViewList.push_back(p);

    p.x = 0.0;
    p.y = 0.0;
    p.z = -35.0;

    pointOfViewList.push_back(p);
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
         Factory::camera->setEyePosition(pointOfViewList[viewPointPositionNumber].x, pointOfViewList[viewPointPositionNumber].y, pointOfViewList[viewPointPositionNumber].z);
         Factory::camera->setCameraDirection(0,0,0);
    }
}

void CameraController::moveCameraToNextViewPoint()
{
    ++ viewPointPositionNumber;
    viewPointPositionNumber %= pointOfViewList.size();
}
