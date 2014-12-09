#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMatrix4x4>
#include <QVector2D>
#include <QGLShaderProgram>
#include "Quaternions.h"
#include "GL/freeglut.h"
#include "Node.h"
#include "Transform.h"
#include "DoorController.h"

class DoorController;

class GLRenderer : public QGLWidget
{
    Q_OBJECT

public:
    GLRenderer(QWidget *parent = 0);
    ~GLRenderer();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    RobotController * getRobotController();

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;
    void keyPressEvent(QKeyEvent *);
    void renderAxes();

private:
    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;
    QColor qtGreen;
    QColor qtPurple;

    float scale;
    float translateX;
    float translateY;
    float translateZ;
    float lightPositionX;
    float lightPositionY;
    float lightPositionZ;
    bool  lightMovementEnabled;
    RobotController *robotController;
    DoorController  *doorController ;

    Quaternions quaternion;
    bool videoPlaying;
};

#endif
