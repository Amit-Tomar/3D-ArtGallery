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
Q_PROPERTY(float robotY READ robotY WRITE setRobotY NOTIFY robotYChanged)
Q_PROPERTY(float robotZ READ robotZ WRITE setRobotZ NOTIFY robotZChanged)

Q_PROPERTY(float interpolationVariable  READ interpolationVariable  WRITE setInterpolationVariable  NOTIFY interpolationVariableChanged )

public:
    RobotController();

    void  moveRobotTo(float, float);
    void  jumpRobot(float);
    void  turnRobot(float, float, float);

    float robotZ() const { return m_robotZ; }
    float robotX() const { return m_robotX; }
    float robotY() const { return m_robotY; }

    void  setRobotX(float robotX){ m_robotX = robotX; emit robotXChanged(robotX);}
    void  setRobotY(float robotY){ m_robotY = robotY; emit robotYChanged(robotY);}
    void  setRobotZ(float robotZ){ m_robotZ = robotZ; emit robotZChanged(robotZ);}

    void  setInterpolationVariable( float value ){ m_interpolationVariable = value; emit interpolationVariableChanged(value); }
    float interpolationVariable()const { return m_interpolationVariable; }

private slots:

    void updateRobotX();
    void updateRobotY();
    void updateRobotZ();
    void updateRobotLeftShoulderAngle();
    void updateRobotRightShoulderAngle();
    void updateLeftLegThighAngle();
    void updateLeftLegKneeAngle();
    void updateRightLegThighAngle();
    void updateRightLegKneeAngle();

signals:
    void    robotXChanged(float);
    void    robotYChanged(float);
    void    robotZChanged(float);
    float   interpolationVariableChanged(float);

public slots:

    void stopRobotMotion();

private:

    QTimer  * robotMotionTimer;

    float   robotLeftArmTopAngle;
    bool    lefthandMotionForward;
    float   INTERPOLATION_MIN;
    float   INTERPOLATION_MAX;
    float   robotSpeed;
    float   robotDestinationX;
    float   robotDestinationY;
    float   robotDestinationZ;

    float   m_robotX;
    float   m_robotY;
    float   m_robotZ;
    float   m_interpolationVariable;

    QPropertyAnimation * animationRobotX;
    QPropertyAnimation * animationRobotY;
    QPropertyAnimation * animationRobotZ;
    QPropertyAnimation * interpolationVariableAnimation;
};

#endif // ROBOTCONTROLLER_H
