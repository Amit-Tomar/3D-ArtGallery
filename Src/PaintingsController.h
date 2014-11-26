#ifndef PAINTINGSCONTROLLER_H
#define PAINTINGSCONTROLLER_H

#include <qpropertyanimation.h>
#include <qobject.h>
#include <FactoryData.h>

class PaintingsController: public QObject
{
    Q_OBJECT    
    Q_PROPERTY(float interpolationVariable  READ interpolationVariable  WRITE setInterpolationVariable  NOTIFY interpolationVariableChanged )

public:
    PaintingsController();
    void startPaintingMotion();

    void  setInterpolationVariable( float value ){ m_interpolationVariable = value; emit interpolationVariableChanged(value); }
    float interpolationVariable()const { return m_interpolationVariable; }

public slots:

    void updatePaintingAngle();

signals:

    float   interpolationVariableChanged(float);

private:

    float   INTERPOLATION_MIN;
    float   INTERPOLATION_MAX;

    float   m_interpolationVariable;
    QPropertyAnimation * interpolationVariableAnimation;
};

#endif // PAINTINGSCONTROLLER_H
