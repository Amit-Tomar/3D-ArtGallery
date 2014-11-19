#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include "FactoryData.h"

class CameraController
{
public:
    CameraController();
    void repositionCamera();
    bool isCameraFollowingRobot(){ return cameraFollowingRobot; }
    void setCameraFollowingRobotStatus(bool status) { cameraFollowingRobot = status ; }

private:

    bool cameraFollowingRobot;
};

#endif // CAMERACONTROLLER_H
