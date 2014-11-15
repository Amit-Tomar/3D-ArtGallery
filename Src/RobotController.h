#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H
#include <cmath>
#include <QPropertyAnimation>
#include <QTimer>

#define PI 3.14159265

class RobotController : public QObject
{

Q_OBJECT

Q_PROPERTY(float robotX READ robotX WRITE setRobotX NOTIFY robotXChanged)
Q_PROPERTY(float robotZ READ robotZ WRITE setRobotZ NOTIFY robotZChanged)

Q_PROPERTY(float leftHandShoulderAngle  READ leftHandShoulderAngle  WRITE setLeftHandShoulderAngle  NOTIFY leftHandShoulderAngleChanged )

Q_PROPERTY(float leftLegThighAngle  READ leftLegThighAngle  WRITE setLeftLegThighAngle  NOTIFY leftLegThighAngleChanged )

public:
    RobotController();

    void  moveRobotTo(float, float);
    void  jumpRobot(float);
    void  turnRobot(float, float, float);
    void  setRobotX(float robotX){ m_robotX = robotX; emit robotXChanged(robotX);}
    float robotX() const { return m_robotX; }
    void  setRobotZ(float robotZ){ m_robotZ = robotZ; emit robotZChanged(robotZ);}
    float robotZ() const { return m_robotZ; }
    void  setLeftHandShoulderAngle( float angle ){ m_leftHandShoulderAngle = angle; emit leftHandShoulderAngleChanged(angle); }
    float leftHandShoulderAngle()const { return m_leftHandShoulderAngle; }
    float leftLegThighAngle()const { return m_leftLegThighAngle; }
    void  setLeftLegThighAngle(float angle) { m_leftLegThighAngle = angle ; emit leftLegThighAngleChanged(angle) ; }

private slots:

    void updateRobotX();
    void updateRobotZ();
    void updateRobotLeftShoulderAngle();
    void updateRobotRightShoulderAngle();
    void updateLeftLegThighAngle();
    void updateLeftLegKneeAngle();
    void updateRightLegThighAngle();
    void updateRightLegKneeAngle();

signals:
    void    robotXChanged(float);
    void    robotZChanged(float);
    float   leftHandShoulderAngleChanged(float);
    float   leftLegThighAngleChanged(float);

public slots:

    void stopRobotMotion();

private:

    QTimer  * robotMotionTimer;

    float   robotLeftArmTopAngle;
    bool    lefthandMotionForward;
    float   LEFT_ARM_MIN_ANGLE;
    float   LEFT_ARM_MAX_ANGLE;
    float   LEFT_THIGH_MIN_ANGLE;
    float   LEFT_THIGH_MAX_ANGLE;
    float   robotSpeed;
    float   robotDestinationX;
    float   robotDestinationZ;

    float   m_robotX;
    float   m_robotZ;
    float   m_leftHandShoulderAngle;
    float   m_leftLegThighAngle;

    QPropertyAnimation * animationRobotX;
    QPropertyAnimation * animationRobotZ;
    QPropertyAnimation * animationLeftHandShoulderAngle;
    QPropertyAnimation * animationLeftLegThighAngle;
};

#endif // ROBOTCONTROLLER_H
