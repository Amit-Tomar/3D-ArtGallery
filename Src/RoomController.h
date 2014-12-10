#ifndef ROOMCONTROLLER_H
#define ROOMCONTROLLER_H

#include <qobject.h>
#include <QPropertyAnimation>
#include "FactoryData.h"

class RoomController: public QObject
{
    Q_OBJECT

    Q_PROPERTY(float interpolationVariable  READ interpolationVariable  WRITE setInterpolationVariable  NOTIFY interpolationVariableChanged )

public:
    RoomController();
    void moveBackWall();

    void  setInterpolationVariable( float value ){ m_interpolationVariable = value; emit interpolationVariableChanged(value); }
    float interpolationVariable()const { return m_interpolationVariable; }

public slots:

    void updateBackWallPosition();

signals:

    float   interpolationVariableChanged(float);

private:

    float   m_interpolationVariable;
    QPropertyAnimation * interpolationVariableAnimation;
    float   INTERPOLATION_MIN;
    float   INTERPOLATION_MAX;
};

#endif // ROOMCONTROLLER_H
