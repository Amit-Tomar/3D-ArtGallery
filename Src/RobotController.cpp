#include "RobotController.h"
#include "FactoryData.h"
using namespace Factory;

RobotController::RobotController()
{
    motionTimer = new QTimer(NULL);
    connect(motionTimer, SIGNAL(timeout()), this, SLOT(updateRobotPosition()));
    robotLeftArmTopAngle = 60;
    lefthandMotionForward = true;
    startRobotMotion(1.0);
    LEFT_ARM_MIN_ANGLE = 60 ;
    LEFT_ARM_MAX_ANGLE = 160;
}

void RobotController::startRobotMotion(float speed)
{
    motionTimer->start();
}

void RobotController::stopRobotMotion()
{

}

void RobotController::jumpRobot(float height)
{

}

void RobotController::turnRobot(float angleX, float angleY, float angleZ)
{

}

void RobotController::updateRobotPosition()
{
    if( robotLeftArmTopAngle == LEFT_ARM_MAX_ANGLE )
        lefthandMotionForward = false;

    else if( robotLeftArmTopAngle == LEFT_ARM_MIN_ANGLE )
        lefthandMotionForward = true;

    if( lefthandMotionForward )
        robotLeftArmTopAngle ++ ;
    else
        robotLeftArmTopAngle -- ;

    robotLeftShoulderTransform->interpolateRotationTo(
                robotLeftArmTopAngle,
                robotLeftShoulderTransform->getRotationY(),
                robotLeftShoulderTransform->getRotationZ());

    robotRightShoulderTransform->interpolateRotationTo(
                220 - robotLeftArmTopAngle,
                robotRightShoulderTransform->getRotationY(),
                robotRightShoulderTransform->getRotationZ());

    robotLeftThighTransform->interpolateRotationTo(
                110 - robotLeftArmTopAngle,
                robotLeftThighTransform->getRotationY(),
                robotLeftThighTransform->getRotationZ());

//    robotLeftKneeTransform->interpolateRotationTo(
//                110 - robotLeftArmTopAngle + 50,
//                robotLeftKneeTransform->getRotationY(),
//                robotLeftKneeTransform->getRotationZ());

    robotRightThighTransform->interpolateRotationTo(
                - 110 + robotLeftArmTopAngle,
                robotRightThighTransform->getRotationY(),
                robotRightThighTransform->getRotationZ());

    std::cout << 110 - robotLeftArmTopAngle << std::endl;
}
