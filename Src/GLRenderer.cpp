#include <QtWidgets>
#include <QtOpenGL>
#include <math.h>
#include "GLRenderer.h"
#include "FactoryData.h"

using namespace Factory;

GLRenderer::GLRenderer(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 5;
    zRot = 145;

    RobotController *robotController = new RobotController();

    qtGreen = QColor::fromCmykF(0.40, 0.0, 1.0, 0.0);
    qtPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
    setFocusPolicy(Qt::ClickFocus);
    scale = .20 ;
    lightPositionX = 1.5 ;
    lightPositionY = 1.5 ;
    lightPositionZ = 1.5 ;
    lightMovementEnabled = true ;

    /*
        Only set the scenegraph here. Don't write any rendering related code here.
    */

    scenegraphRootNode->addChild(camera);
    scenegraphRootNode->addChild(centralLightSource);
    scenegraphRootNode->addChild(robotRootNode);
    scenegraphRootNode->addChild(roomRootNode);

    robotRootNode->addChild(robotTorsoTransform);
    robotTorsoTransform->addChild(robotTorso);
    robotTorso->addChild(robotHeadTransform);
    robotHeadTransform->addChild(robotHead);


    // Left Hand
    robotTorso->addChild(robotLeftShoulderTransform);
    robotLeftShoulderTransform->addChild(robotLeftArmTop);
    robotLeftArmTop->addChild(robotLeftElbowTransform);
    robotLeftElbowTransform->addChild(robotLeftBottom);

    // Right hand
    robotTorso->addChild(robotRightShoulderTransform);
    robotRightShoulderTransform->addChild(robotRightArmTop);
    robotRightArmTop->addChild(robotRightElbowTransform);
    robotRightElbowTransform->addChild(robotRightBottom);

    // Left Leg
    robotTorso->addChild(robotLeftThighTransform);
    robotLeftThighTransform->addChild(robotLeftLegTop);
    robotLeftLegTop->addChild(robotLeftKneeTransform);
    robotLeftKneeTransform->addChild(robotLeftLegBottom);

    // Right Leg
    robotTorso->addChild(robotRightThighTransform);
    robotRightThighTransform->addChild(robotRightLegTop);
    robotRightLegTop->addChild(robotRightKneeTransform);
    robotRightKneeTransform->addChild(robotRightLegBottom);

    roomRootNode->addChild(roomCentralTransform);
    roomCentralTransform->addChild(roomModel);

    robotHeadTransform->interpolateTranslationTo(0,1.50,0);
    robotHeadTransform->setColor(1,0,0);
    robotHeadTransform->interpolateScaleTo(1,1.25,1);

    robotTorsoTransform->setColor(1,1,0);

    robotLeftThighTransform->interpolateTranslationTo(-.30,-1,0);
    robotLeftThighTransform->setColor(.8,.5,0);

    robotRightThighTransform->interpolateTranslationTo( .30,-1,0);
    robotRightThighTransform->setColor(.8,.5,0);

    robotLeftKneeTransform->interpolateTranslationTo(0,-.40,0);
    robotLeftKneeTransform->setColor(.6,.3,0);
    robotLeftKneeTransform->interpolateRotationTo(-60,0,0);
    robotLeftKneeTransform->setRotationPoint(0,-.55,0);

    robotRightKneeTransform->interpolateTranslationTo(0,-.40,0);
    robotRightKneeTransform->setColor(.6,.3,0);
    robotRightKneeTransform->interpolateRotationTo(-60,0,0);
    robotRightKneeTransform->setRotationPoint(0,-.55,0);

    robotLeftShoulderTransform->interpolateTranslationTo(-.35,.85,0);
    robotLeftShoulderTransform->interpolateRotationTo(90,-25,0);
    robotLeftShoulderTransform->setColor(0,.8,.25);

    robotRightShoulderTransform->interpolateTranslationTo(.35,.85,0);
    robotRightShoulderTransform->interpolateRotationTo(90,25,0);
    robotRightShoulderTransform->setColor(0,.8,.25);

    robotLeftElbowTransform->interpolateTranslationTo(0,0,.90);
    robotLeftElbowTransform->interpolateRotationTo(-50,20,0);
    robotLeftElbowTransform->setColor(0,.5,.15);

    robotRightElbowTransform->interpolateTranslationTo(0,0,.90);
    robotRightElbowTransform->interpolateRotationTo(-50,-20,0);
    robotRightElbowTransform->setColor(0,.5,.15);

    robotTorsoTransform->interpolateScaleTo(.5,.5,.5);
    robotTorsoTransform->interpolateTranslationTo(0,0,10,5000);
    //robotTorsoTransform->interpolateRotationTo(45,0,0);
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

    // Scenegraph Traversal
    glPushMatrix();
    scenegraphRootNode->depthFirstTraversal();
    glPopMatrix();

    // Draw  Axis
    renderAxes();
    update();
}

void GLRenderer::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    //@TBD To check, why this ?
    glViewport((width - side) / 2, (height - side) / 2, side, side);
    //glViewport(0,0,width,height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
}

void GLRenderer::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

/*
    Handle key press events
*/
void GLRenderer::keyPressEvent(QKeyEvent *keyevent)
{


    glDraw();
    update();
}

void GLRenderer::renderAxes()
{
    float length = 100.0;
    glLineWidth(2);
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
