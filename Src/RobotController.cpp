#include "RobotController.h"
#include "FactoryData.h"
using namespace Factory;

RobotController::RobotController()
{
    robotLeftArmTopAngle = 60;
    lefthandMotionForward = true;
    LEFT_ARM_MIN_ANGLE   = 50 ;
    LEFT_ARM_MAX_ANGLE   = 150;
    LEFT_THIGH_MIN_ANGLE = 50 ;
    LEFT_THIGH_MAX_ANGLE = -50;
    robotSpeed = .0001;
    animationRobotX = new QPropertyAnimation(this, "robotX");
    animationRobotZ = new QPropertyAnimation(this, "robotZ");
    animationLeftHandShoulderAngle  = new QPropertyAnimation(this, "leftHandShoulderAngle");
    animationLeftLegThighAngle      = new QPropertyAnimation(this, "leftLegThighAngle");

    QObject::connect(this, SIGNAL(robotZChanged(float)), this, SLOT(updateRobotZ()));
    QObject::connect(this, SIGNAL(robotXChanged(float)), this, SLOT(updateRobotX()));
    QObject::connect(this, SIGNAL(leftHandShoulderAngleChanged(float)), this, SLOT(updateRobotLeftShoulderAngle()));
    QObject::connect(this, SIGNAL(leftLegThighAngleChanged(float)), this, SLOT(updateLeftLegThighAngle()));
}

void RobotController::moveRobotTo(float finalX , float finalZ )
{
    if( finalZ > 0 )
        robotTorsoTransform->setRotationTo(0, atan(finalX/finalZ) * 57.2957795130,0);
    else
        robotTorsoTransform->setRotationTo(0, 180 + atan(finalX/finalZ) * 57.2957795130,0);

    robotDestinationX = finalX;
    robotDestinationZ = finalZ;

    float distanceToDestination = sqrt( ((finalX-robotTorsoTransform->getTranslationX()) * (finalX-robotTorsoTransform->getTranslationX()))  + ((finalZ-robotTorsoTransform->getTranslationZ()) * (finalZ-robotTorsoTransform->getTranslationZ())) );
    float time = distanceToDestination / robotSpeed;

    animationRobotX->setDuration(time);
    animationRobotZ->setDuration(time);
    animationLeftHandShoulderAngle->setDuration(2000);
    animationLeftLegThighAngle->setDuration(2000);

    animationRobotX->setKeyValueAt (0, robotTorsoTransform->getTranslationX());
    animationRobotX->setKeyValueAt (1, finalX );
    animationRobotX->start();

    animationRobotZ->setKeyValueAt (0, robotTorsoTransform->getTranslationZ());
    animationRobotZ->setKeyValueAt (1, finalZ );
    animationRobotZ->start();

    animationLeftHandShoulderAngle->setKeyValueAt(0,LEFT_ARM_MIN_ANGLE);
    animationLeftHandShoulderAngle->setKeyValueAt(.5,LEFT_ARM_MAX_ANGLE);
    animationLeftHandShoulderAngle->setKeyValueAt(1,LEFT_ARM_MIN_ANGLE);
    animationLeftHandShoulderAngle->setLoopCount(-1);
    animationLeftHandShoulderAngle->start();

    animationLeftLegThighAngle->setKeyValueAt(0,LEFT_THIGH_MIN_ANGLE);
    animationLeftLegThighAngle->setKeyValueAt(.5,LEFT_THIGH_MAX_ANGLE);
    animationLeftLegThighAngle->setKeyValueAt(1,LEFT_THIGH_MIN_ANGLE);
    animationLeftLegThighAngle->setLoopCount(-1);
    animationLeftLegThighAngle->start();
}

void RobotController::stopRobotMotion()
{
    animationLeftHandShoulderAngle->stop();
    animationRobotX->stop();
    animationRobotZ->stop();
}

void RobotController::jumpRobot(float height)
{

}

void RobotController::turnRobot(float angleX, float angleY, float angleZ)
{

}

void RobotController::updateRobotX()
{
    robotTorsoTransform->setTranslationTo(m_robotX,robotTorsoTransform->getTranslationY(),robotTorsoTransform->getTranslationZ());
}

void RobotController::updateRobotZ()
{
    robotTorsoTransform->setTranslationTo(robotTorsoTransform->getTranslationX(),robotTorsoTransform->getTranslationY(), m_robotZ);
}

void RobotController::updateRobotLeftShoulderAngle()
{
    robotLeftShoulderTransform->setRotationTo(m_leftHandShoulderAngle,robotLeftShoulderTransform->getRotationY(), robotLeftShoulderTransform->getRotationZ());
    updateRobotRightShoulderAngle();
}

void RobotController::updateRobotRightShoulderAngle()
{
    robotRightShoulderTransform->setRotationTo(LEFT_ARM_MAX_ANGLE + LEFT_ARM_MIN_ANGLE - m_leftHandShoulderAngle,robotRightShoulderTransform->getRotationY(), robotRightShoulderTransform->getRotationZ());
}

void RobotController::updateLeftLegThighAngle()
{
        robotLeftThighTransform->setRotationTo(
                    m_leftLegThighAngle,
                    robotLeftThighTransform->getRotationY(),
                    robotLeftThighTransform->getRotationZ());

        updateLeftLegKneeAngle();
        updateRightLegThighAngle();
}

void RobotController::updateRightLegThighAngle()
{
    robotRightThighTransform->setRotationTo(
                -m_leftLegThighAngle,
                robotRightThighTransform->getRotationY(),
                robotRightThighTransform->getRotationZ());

    updateRightLegKneeAngle();
}

void RobotController::updateRightLegKneeAngle()
{
    robotRightKneeTransform->setRotationTo(
                -((LEFT_THIGH_MAX_ANGLE - m_leftLegThighAngle)/3),
                robotRightKneeTransform->getRotationY(),
                robotRightThighTransform->getRotationZ());
}

void RobotController::updateLeftLegKneeAngle()
{
    robotLeftKneeTransform->setRotationTo(
                (LEFT_THIGH_MIN_ANGLE - m_leftLegThighAngle)/3,
                robotLeftKneeTransform->getRotationY(),
                robotLeftKneeTransform->getRotationZ());
}
