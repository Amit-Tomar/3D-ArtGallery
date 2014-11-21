#ifndef DOORCONTROLLER_H
#define DOORCONTROLLER_H

#include <qobject.h>
#include <QPropertyAnimation>
#include "FactoryData.h"

using namespace Factory;

class DoorController: public QObject
{
    Q_OBJECT

    Q_PROPERTY(float interpolationVariable  READ interpolationVariable  WRITE setInterpolationVariable  NOTIFY interpolationVariableChanged )

public:
    DoorController();
    void openDoor();
    void closeDoor();

    void  setInterpolationVariable( float value ){ m_interpolationVariable = value; emit interpolationVariableChanged(value); }
    float interpolationVariable()const { return m_interpolationVariable; }

public slots:

    void updateDoorPositions();

signals:

    float   interpolationVariableChanged(float);

private:

    float   m_interpolationVariable;
    QPropertyAnimation * interpolationVariableAnimation;
    float   INTERPOLATION_MIN;
    float   INTERPOLATION_MAX;
};

#endif // DOORCONTROLLER_H
