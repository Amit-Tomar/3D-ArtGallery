#ifndef PAINTINGSCONTROLLER_H
#define PAINTINGSCONTROLLER_H

#include <qpropertyanimation.h>
#include <qobject.h>
#include <FactoryData.h>

class PaintingsController: public QObject
{
    Q_OBJECT    
    Q_PROPERTY(float interpolVarHanging  READ interpolVarHanging  WRITE setInterpolVarHanging  NOTIFY interpolVarHangingChanged )
    Q_PROPERTY(float interpolVarFalling  READ interpolVarFalling  WRITE setInterpolVarFalling  NOTIFY interpolVarFallingChanged )

public:
    PaintingsController();
    void startPaintingHangingMotion();
    void startPaintingFallingMotion();

    void  setInterpolVarHanging( float value ){ m_interpolVarHanging = value; emit interpolVarHangingChanged(value); }
    float interpolVarHanging()const { return m_interpolVarHanging; }

    void  setInterpolVarFalling( float value ){ m_interpolVarFalling = value; emit interpolVarFallingChanged(value); }
    float interpolVarFalling()const { return m_interpolVarFalling; }

public slots:

    void updatePaintingHangAngle();
    void updatePaintingFallAngle();

signals:

    float   interpolVarHangingChanged(float);
    float   interpolVarFallingChanged(float);

private:

    float   INTERPOLATION_MIN;
    float   INTERPOLATION_MAX;

    float   m_interpolVarHanging;
    float   m_interpolVarFalling;
    QPropertyAnimation * interpolVarHangingAnimation;
    QPropertyAnimation * interpolVarFallingAnimation;
};

#endif // PAINTINGSCONTROLLER_H
