#include "RobotController.h"
#include "FactoryData.h"
using namespace Factory;

RobotController::RobotController(): QObject( NULL )
{
    robotLeftArmTopAngle = 60;
    lefthandMotionForward = true;
    INTERPOLATION_MIN   = 0 ;
    INTERPOLATION_MAX   = 100;
    robotSpeed = .005;
    animationRobotX = new QPropertyAnimation(this, "robotX");
    animationRobotY = new QPropertyAnimation(this, "robotY");
    animationRobotZ = new QPropertyAnimation(this, "robotZ");
    interpolationVariableAnimation  = new QPropertyAnimation(this, "interpolationVariable");

    QObject::connect(this, SIGNAL(robotXChanged(float)), this, SLOT(updateRobotX()));
    QObject::connect(this, SIGNAL(robotYChanged(float)), this, SLOT(updateRobotY()));
    QObject::connect(this, SIGNAL(robotZChanged(float)), this, SLOT(updateRobotZ()));

    QObject::connect(animationRobotX, SIGNAL(finished()), this, SLOT(stopRobotMotion()));
    QObject::connect(this, SIGNAL(interpolationVariableChanged(float)), this, SLOT(updateRobotLeftShoulderAngle()));
}

void RobotController::moveRobotTo(float finalX , float finalZ )
{
    stopRobotMotion();

    if( finalZ > 0 )
        robotTorsoTransform->setRotationTo(0, atan(finalX/finalZ) * 57.2957795130,0);
    else
        robotTorsoTransform->setRotationTo(0, 180 + atan(finalX/finalZ) * 57.2957795130,0);

    robotDestinationX = finalX;
    robotDestinationY = 0;
    robotDestinationZ = finalZ;

    float distanceToDestination = sqrt( ((finalX-robotTorsoTransform->getTranslationX()) * (finalX-robotTorsoTransform->getTranslationX()))  + ((finalZ-robotTorsoTransform->getTranslationZ()) * (finalZ-robotTorsoTransform->getTranslationZ())) );
    float time = distanceToDestination / robotSpeed;

    animationRobotX->setDuration(time);
    animationRobotZ->setDuration(time);
    interpolationVariableAnimation->setDuration(2000);

    animationRobotX->setKeyValueAt (0, robotTorsoTransform->getTranslationX());
    animationRobotX->setKeyValueAt (1, finalX );
    animationRobotX->start();

    animationRobotZ->setKeyValueAt (0, robotTorsoTransform->getTranslationZ());
    animationRobotZ->setKeyValueAt (1, finalZ );
    animationRobotZ->start();

    interpolationVariableAnimation->setKeyValueAt(0,INTERPOLATION_MIN);
    interpolationVariableAnimation->setKeyValueAt(.5,INTERPOLATION_MAX);
    interpolationVariableAnimation->setKeyValueAt(1,INTERPOLATION_MIN);
    interpolationVariableAnimation->setLoopCount(-1);
    interpolationVariableAnimation->start();
}

void RobotController::stopRobotMotion()
{
    interpolationVariableAnimation->stop();
    animationRobotX->stop();
    animationRobotZ->stop();

    robotLeftThighTransform->setTranslationTo(-.30,-1,0);
    robotRightThighTransform->setTranslationTo( .30,-1,0);
    robotLeftThighTransform->setRotationTo(0,0,0);
    robotRightThighTransform->setRotationTo(0,0,0);
    robotLeftKneeTransform->setRotationTo(0,0,0);
    robotRightKneeTransform->setRotationTo(0,0,0);

    robotLeftShoulderTransform->setRotationTo(90,-25,0);
    robotRightShoulderTransform->setRotationTo(90,25,0);
    robotLeftElbowTransform->setRotationTo(-50,20,0);
    robotRightElbowTransform->setRotationTo(-50,-20,0);
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

void RobotController::updateRobotY()
{
    robotTorsoTransform->setTranslationTo(robotTorsoTransform->getTranslationX(),m_robotY,robotTorsoTransform->getTranslationZ());
}

void RobotController::updateRobotZ()
{
    robotTorsoTransform->setTranslationTo(robotTorsoTransform->getTranslationX(),robotTorsoTransform->getTranslationY(), m_robotZ);
}

void RobotController::updateRobotLeftShoulderAngle()
{
    /*
        If var X goes from 0 - 100
        and we want to interpolate Y from c to d

        Y = (d-c)*X/100 + c

        If var X goes from a - b
        and we want to interpolate Y from c to d

        Y = (d-c)*(X-a)/(b-a) + c
    */
    robotLeftShoulderTransform->setRotationTo( ((130-70)*m_interpolationVariable)/100 + 70  ,robotLeftShoulderTransform->getRotationY(), robotLeftShoulderTransform->getRotationZ());
    updateRobotRightShoulderAngle();
    updateLeftLegThighAngle();
    updateLeftLegKneeAngle();
    updateRightLegKneeAngle();
    updateRightLegThighAngle();

    if( robotLeftShoulderTransform->getRotationX() > 120 || robotLeftShoulderTransform->getRotationX() < 80  )
        audioPlayer->playBootSound();

    std::cout << robotLeftShoulderTransform->getRotationX() << std::endl ;
}

void RobotController::updateRobotRightShoulderAngle()
{
    robotRightShoulderTransform->setRotationTo( ((70-130)*m_interpolationVariable)/100 + 130   ,robotRightShoulderTransform->getRotationY(), robotRightShoulderTransform->getRotationZ());
}

void RobotController::updateLeftLegThighAngle()
{
        robotLeftThighTransform->setRotationTo(
                    ((-35-30)*m_interpolationVariable)/100 + 30,
                    robotLeftThighTransform->getRotationY(),
                    robotLeftThighTransform->getRotationZ());
}

void RobotController::updateLeftLegKneeAngle()
{
    robotLeftKneeTransform->setRotationTo(
                ((5-20)*m_interpolationVariable)/100 + 20,
                robotLeftKneeTransform->getRotationY(),
                robotLeftKneeTransform->getRotationZ());
}

void RobotController::updateRightLegThighAngle()
{
    robotRightThighTransform->setRotationTo(
                -((-35-30)*m_interpolationVariable)/100 - 30,
                robotRightThighTransform->getRotationY(),
                robotRightThighTransform->getRotationZ());
}

void RobotController::updateRightLegKneeAngle()
{
    robotRightKneeTransform->setRotationTo(
                ((5-20)*m_interpolationVariable)/100 + 20,
                robotRightKneeTransform->getRotationY(),
                robotRightThighTransform->getRotationZ());
}
