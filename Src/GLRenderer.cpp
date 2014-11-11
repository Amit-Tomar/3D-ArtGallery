#include <QtWidgets>
#include <QtOpenGL>

#include <math.h>
#include "GLRenderer.h"

GLRenderer::GLRenderer(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 5;
    zRot = 145;

    qtGreen = QColor::fromCmykF(0.40, 0.0, 1.0, 0.0);
    qtPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
    setFocusPolicy(Qt::ClickFocus);
    scale = .20 ;
    lightPositionX = 1.5 ;
    lightPositionY = 1.5 ;
    lightPositionZ = 1.5 ;
    lightMovementEnabled = false ;

//    mainScene->addChild(&mainTransformBelt1);
//    mainScene->addChild(&mainTransformBelt2);
//    mainScene->addChild(&mainTransformRobot);
//    mainScene->addChild(&transformBox);

//    mainTransformBelt1.addChild(&belt1);
//    mainTransformBelt2.addChild(&belt2);
//    mainTransformRobot.addChild(&robotBase);
//    mainTransformRobot.setColor(1.0,1.0,1.0);

//    transformRobotArm2.addChild(&joint1);
//    transformRobotArm3.addChild(&joint2);

//    robotBase.addChild(&transformRobotArm1);
//    transformRobotArm1.addChild(&robotArm1);
//    robotArm1.addChild(&transformRobotArm2);
//    transformRobotArm2.addChild(&robotArm2);
//    robotArm2.addChild(&transformRobotArm3);
//    transformRobotArm3.addChild(&robotArm3);

//    transformBox.addChild(&box);
//    transformBox.interpolateTranslationTo(-2,-.15,-2);

//    transformRobotArm1.interpolateTranslationTo(0,0,0);
//    transformRobotArm2.interpolateTranslationTo(0,0,1.5);
//    transformRobotArm3.interpolateTranslationTo(0,0,.5);

//    transformRobotArm1.interpolateRotationTo(0,0,0);
//    transformRobotArm2.interpolateRotationTo(0,0,0);
//    transformRobotArm3.interpolateRotationTo(0,0,0);

//    mainTransformBelt1.interpolateTranslationTo(-2,0,0);
//    mainTransformBelt2.interpolateTranslationTo(1.8,-.25,0);
//    mainTransformBelt1.interpolateRotationTo(0,0,90);
//    mainTransformBelt2.interpolateRotationTo(0,0,90);

//    transformBox.interpolateScaleTo(.35,.35,.35);

//    transformRobotArm1.setColor(1,0,0);
//    transformRobotArm2.setColor(0,1,1);
//    transformRobotArm3.setColor(0,0,.85);
//    transformBox.setColor(1,1,0);
//    mainTransformBelt1.setColor((double)130/255,(double)130/255,(double)130/255);
//    mainTransformBelt2.setColor((double)130/255,(double)130/255,(double)130/255);
}

GLRenderer::~GLRenderer()
{
}

QSize GLRenderer::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLRenderer::sizeHint() const
{
    return QSize(1500, 800);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void GLRenderer::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        //emit xRotationChanged(angle);
        updateGL();
    }
}

void GLRenderer::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        //emit yRotationChanged(angle);
        updateGL();
    }
}

void GLRenderer::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        //emit zRotationChanged(angle);
        updateGL();
    }
}

void GLRenderer::initializeGL()
{
    qglClearColor(qtPurple.dark());
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
}

void GLRenderer::paintGL()
{
    GLfloat light_position[] = { lightPositionX, lightPositionY, lightPositionZ, 0.0 };
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_NORMALIZE);

    glLoadIdentity();

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glTranslatef( 0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

    glScalef(scale,scale,scale);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    float color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glEnable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT, GL_AMBIENT, color);

    //mainScene->depthFirstTraversal();

    // Axis
    float length = 100.0;

    glLineWidth(0.50);
    glColor3f(.1,.2,.5);

    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(length,0,0);

    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,length,0);

    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,length);
    glEnd();

    //glutSolidCone(.55,.55,22,22);

    update();
}

void GLRenderer::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    //@TBD To check, why this ?
    //glViewport((width - side) / 2, (height - side) / 2, side, side);
    glViewport(0,0,width,height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
}

void GLRenderer::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLRenderer::keyPressEvent(QKeyEvent *keyevent)
{
//    // Scale
//    if( keyevent->key() == Qt::Key_Q )
//    {
//        std::cout << "Updated Arm 1" << std::endl ;
//        transformRobotArm1.interpolateRotationTo(transformRobotArm1.getRotationX()+5,transformRobotArm1.getRotationY(),transformRobotArm1.getRotationZ());
//    }

//    else if( keyevent->key() == Qt::Key_W )
//    {
//        std::cout << "Updated Arm 1" << std::endl ;
//        transformRobotArm1.interpolateRotationTo(transformRobotArm1.getRotationX(),transformRobotArm1.getRotationY()+5,transformRobotArm1.getRotationZ());
//    }

//    else if( keyevent->key() == Qt::Key_E )
//    {
//        std::cout << "Updated Arm 1" << std::endl ;
//        transformRobotArm1.interpolateRotationTo(transformRobotArm1.getRotationX(),transformRobotArm1.getRotationY(),transformRobotArm1.getRotationZ()+5);
//    }

//    else if( keyevent->key() == Qt::Key_A )
//    {
//        std::cout << "Updated Arm 2" << std::endl ;
//        transformRobotArm2.interpolateRotationTo(transformRobotArm2.getRotationX()+5,transformRobotArm2.getRotationY(),transformRobotArm2.getRotationZ());
//    }

//    else if( keyevent->key() == Qt::Key_S )
//    {
//        std::cout << "Updated Arm 2" << std::endl ;
//        transformRobotArm2.interpolateRotationTo(transformRobotArm2.getRotationX(),transformRobotArm2.getRotationY()+5,transformRobotArm2.getRotationZ());
//    }

//    else if( keyevent->key() == Qt::Key_D )
//    {
//        std::cout << "Updated Arm 2" << std::endl ;
//        transformRobotArm2.interpolateRotationTo(transformRobotArm2.getRotationX(),transformRobotArm2.getRotationY(),transformRobotArm2.getRotationZ()+5);
//    }

//    else if( keyevent->key() == Qt::Key_Z )
//    {
//        std::cout << "Updated Arm 3" << std::endl ;
//        transformRobotArm3.interpolateRotationTo(transformRobotArm3.getRotationX()+5,transformRobotArm3.getRotationY(),transformRobotArm3.getRotationZ());
//    }

//    else if( keyevent->key() == Qt::Key_X )
//    {
//        std::cout << "Updated Arm 3" << std::endl ;
//        transformRobotArm3.interpolateRotationTo(transformRobotArm3.getRotationX(),transformRobotArm3.getRotationY()+5,transformRobotArm3.getRotationZ());
//    }

//    else if( keyevent->key() == Qt::Key_C )
//    {
//        std::cout << "Updated Arm 3" << std::endl ;
//        transformRobotArm3.interpolateRotationTo(transformRobotArm3.getRotationX(),transformRobotArm3.getRotationY(),transformRobotArm3.getRotationZ()+5);
//    }

//    else if( keyevent->key() == Qt::Key_P )
//    {
//        transformRobotArm1.interpolateRotationTo(90, -20, 260, 2000);
//        transformRobotArm2.interpolateRotationTo(60, 15, 75, 2000);
//        transformRobotArm3.interpolateRotationTo(45, 310, 55, 2000);
//    }

//    else if( keyevent->key() == Qt::Key_O )
//    {
//        transformRobotArm1.interpolateRotationTo(95, 10, 80, 4000);
//        transformRobotArm2.interpolateRotationTo(60, 15, 75, 4000);
//        transformRobotArm3.interpolateRotationTo(40, 295, 52, 4000);
//    }

//    else if( keyevent->key() == Qt::Key_K )
//    {
//        transformRobotArm3.addChild(&transformBox);
//        mainScene->removeChild(3);
//        transformBox.stopTranslation();
//        transformBox.interpolateTranslationTo(0,0,1.5);
//    }

//    else if( keyevent->key() == Qt::Key_L )
//    {
//        mainScene->addChild(&transformBox);
//        transformRobotArm3.removeChild(2);
//        transformBox.interpolateTranslationTo(1.8,-.25,0);
//        transformBox.interpolateTranslationTo(1.8,-.45,0);
//        transformBox.interpolateTranslationTo(1.8,-.45,2,1);
//    }

//    else if( keyevent->key() == Qt::Key_I )
//    {
//        transformBox.interpolateTranslationTo(-2,-.2, 2,1);
//    }

    glDraw();
    update();
}

void GLRenderer::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }
    lastPos = event->pos();
}
