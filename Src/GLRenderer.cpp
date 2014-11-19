#include <QWidget>
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

    /*
        Robot controller is declared here because signals/slots require a UI
        thread of their own to be running.
    */
    robotController = new RobotController();

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
    scenegraphRootNode->addChild(roomCentralTransform);

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

    // Left shoe
    robotLeftLegBottom->addChild(robotLeftShoeTransform);
    robotLeftShoeTransform->addChild(robotLeftShoe);

    // Right shoe
    robotRightLegBottom->addChild(robotRightShoeTransform);
    robotRightShoeTransform->addChild(robotRightShoe);

    // Add room walls

    roomCentralTransform->addChild(roomRootNode);

    roomRootNode->addChild(roomFloorTransform);
    roomFloorTransform->addChild(roomFloor);

    roomRootNode->addChild(roomLeftWallTransform);
    roomLeftWallTransform->addChild(roomLeftWall);

    roomRootNode->addChild(roomRightWallTransform);
    roomRightWallTransform->addChild(roomRightWal);

    roomRootNode->addChild(roomFrontWallTransform);
    roomFrontWallTransform->addChild(roomFrontWal);

//    roomRootNode->addChild(roomBackWallTransform);
//    roomBackWallTransform->addChild(roomBackWall);

//    roomRootNode->addChild(roomCeilingTransform);
//    roomCeilingTransform->addChild(roomCeiling);

    // Apply Transforms

    robotHeadTransform->setTranslationTo(0,1.50,0);
    robotHeadTransform->setColor(1,0,0);
    robotHeadTransform->setScaleTo(1,1.25,1);

    robotTorsoTransform->setColor(1,1,0);
    robotTorsoTransform->setTranslationTo(0,0,0);

    robotLeftThighTransform->setTranslationTo(-.30,-1,0);
    robotLeftThighTransform->setColor(.8,.5,0);

    robotRightThighTransform->setTranslationTo( .30,-1,0);
    robotRightThighTransform->setColor(.8,.5,0);

    robotLeftKneeTransform->setTranslationTo(0,-.40,0);
    robotLeftKneeTransform->setColor(.6,.3,0);
    robotLeftKneeTransform->setRotationTo(0,0,0);
    robotLeftKneeTransform->setRotationPoint(0,-.55,0);

    robotRightKneeTransform->setTranslationTo(0,-.40,0);
    robotRightKneeTransform->setColor(.6,.3,0);
    robotRightKneeTransform->setRotationTo(0,0,0);
    robotRightKneeTransform->setRotationPoint(0,-.55,0);

    robotLeftShoulderTransform->setTranslationTo(-.35,.85,0);
    robotLeftShoulderTransform->setRotationTo(90,-25,0);
    robotLeftShoulderTransform->setColor(0,.8,.25);

    robotRightShoulderTransform->setTranslationTo(.35,.85,0);
    robotRightShoulderTransform->setRotationTo(90,25,0);
    robotRightShoulderTransform->setColor(0,.8,.25);

    robotLeftElbowTransform->setTranslationTo(0,0,.90);
    robotLeftElbowTransform->setRotationTo(-50,20,0);
    robotLeftElbowTransform->setColor(0,.5,.15);

    robotRightElbowTransform->setTranslationTo(0,0,.90);
    robotRightElbowTransform->setRotationTo(-50,-20,0);
    robotRightElbowTransform->setColor(0,.5,.15);

    robotLeftShoeTransform->setTranslationTo(0,-.70,.15);
    robotLeftShoeTransform->setRotationTo(90,0,0);

    robotRightShoeTransform->setTranslationTo(0,-.70,.15);
    robotRightShoeTransform->setRotationTo(90,0,0);

    unsigned int roomScale = 40 ;

    // Room transforms
    roomFloorTransform->setTranslationTo(0,-8,0);
    roomFloorTransform->setScaleTo(roomScale* 1.5,roomScale* 1.5,roomScale* 3.5);

    roomLeftWallTransform->setTranslationTo(-30,10,0);
    roomLeftWallTransform->setScaleTo(roomScale,1,roomScale);
    roomLeftWallTransform->setRotationTo(0,0,-90);

    roomRightWallTransform->setTranslationTo(30,10,0);
    roomRightWallTransform->setScaleTo(roomScale,1,roomScale);
    roomRightWallTransform->setRotationTo(0,0,90);

    roomFrontWallTransform->setTranslationTo(0,0,-20);
    roomFrontWallTransform->setScaleTo(roomScale*1.5,1,roomScale*1.5);
    roomFrontWallTransform->setRotationTo(90,0,0);

    // For testing
    robotTorsoTransform->setScaleTo(2.5,2.5,2.5);
    robotController->moveRobotTo(-10,20);
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

    // For rotating the scene using mouse
//    glTranslatef( 0.0, 0.0, -10.0);
//    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
//    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
//    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

//    glScalef(scale,scale,scale);


    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    float color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glEnable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT, GL_AMBIENT, color);

    gluLookAt(robotTorsoTransform->getTranslationX(), robotTorsoTransform->getTranslationY(), robotTorsoTransform->getTranslationZ(), robotController->getRobotDestinationX(),robotController->getRobotDestinationY(),robotController->getRobotDestinationZ(),0,1,0);

    std::cout << "Look at : " << robotTorsoTransform->getTranslationX() << " : " << robotTorsoTransform->getTranslationY() << " : " << robotTorsoTransform->getTranslationZ() << std::endl ;

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
    //@TBD To check, why this ?
        //glViewport((width - side) / 2, (height - side) / 2, side, side);
        glViewport(0,0,width,height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(100,width/height,1,100);
        //glTranslatef(-1,-1,-1);
        //glOrtho(-1, +1, -1, +1, 4.0, 15.0);
        //gluLookAt(0,0,45,0,0,0,0,1,0);
        glMatrixMode(GL_MODELVIEW);
        //gluLookAt(20,0,5,0,0,0,0,1,0);

        //glTranslatef(1,1,1);
}

void GLRenderer::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();

//    float window_width,window_height;
//      float ratio_x,ratio_y,cy;
//      float click_x=event->x();
//      float click_y=event->y();
//      //  qDebug()<<"screen cx1==="<<cx1;
//      // qDebug()<<"screen cy1==="<<cy1;

//      window_width  = this->width();
//      window_height = this->height();

//      ratio_x=30.0/window_width;
//      ratio_y=30.0/window_height;
//      cy=window_height-click_y;
//      click_x=click_x*ratio_x-10;
//      click_y=cy*ratio_y-10;

//      //robotController->stopRobotMotion();
//      //robotController->moveRobotTo(click_x,click_y);

////      //qDebug()<<"original_position_on_screen x==="<<click_x;
////      //qDebug()<<"original_position_on_screen y==="<<click_y;

//        lastPos = event->pos();
//        GLfloat wx=click_x;
//        GLfloat wy=click_y;
//        GLfloat wz;
//        glReadPixels(wx,wy,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&wz);
//        //printf("--- %f %f %f\n", wx,wy,wz);// wx,wy and wz are x,y,z coordinates on mouse click
//        std::cout << "---   " << wx << "  " << wy << "   " << wz << "  " << std::endl;

//        //robotController->stopRobotMotion();
//        robotController->moveRobotTo(wx,wz);



}

/*
    Handle key press events
*/
void GLRenderer::keyPressEvent(QKeyEvent *keyevent)
{
    // Scale
    if( keyevent->key() == Qt::Key_C )
    {

    }

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
