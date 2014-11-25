#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include "FactoryData.h"

typedef struct
{
    float x;
    float y;
    float z;
}Point;

class CameraController
{
public:
    CameraController();
    void repositionCamera();
    bool isCameraFollowingRobot(){ return cameraFollowingRobot; }
    void setCameraFollowingRobotStatus(bool status) { cameraFollowingRobot = status ; }
    void moveCameraToNextViewPoint();

private:

    bool cameraFollowingRobot;
    std::vector<Point> pointOfViewList;
    int viewPointPositionNumber;
};

#endif // CAMERACONTROLLER_H
