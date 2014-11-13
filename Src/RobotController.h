#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H
#include <cmath>
#include <QTimer>

#define PI 3.14159265

class RobotController : public QObject
{

Q_OBJECT

public:
    RobotController();
    void startRobotMotion(float);
    void stopRobotMotion();
    void jumpRobot(float);
    void turnRobot(float, float, float);

private slots :

    void updateRobotPosition();

private:

    QTimer  * motionTimer;
    float   robotLeftArmTopAngle;
    bool    lefthandMotionForward;
    float   LEFT_ARM_MIN_ANGLE;
    float   LEFT_ARM_MAX_ANGLE;
};

#endif // ROBOTCONTROLLER_H
