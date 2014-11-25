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
    doorController  = new DoorController();

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
    roomRightWallTransform->addChild(roomRightWall);

    roomRootNode->addChild(roomFrontWallTransform);
    roomFrontWallTransform->addChild(roomFrontWall);

    roomRootNode->addChild(roomFrontWallLeftDoorTransform);
    roomFrontWallLeftDoorTransform->addChild(roomFrontWallLeftDoor);

    roomRootNode->addChild(roomFrontWallRightDoorTransform);
    roomFrontWallRightDoorTransform->addChild(roomFrontWallRightDoor);

    roomRootNode->addChild(roomBackWallTransform);
    roomBackWallTransform->addChild(roomBackWall);

    roomRootNode->addChild(roomCeilingTransform);
    roomCeilingTransform->addChild(roomCeiling);

    roomRootNode->addChild(roomFrontWallInTransform);
    roomFrontWallInTransform->addChild(roomFrontWallIn);

    // Add paintings
	roomRootNode->addChild(painting1Transform);
    painting1Transform->addChild(painting1);

    roomRootNode->addChild(painting2Transform);
    painting2Transform->addChild(painting2);

    roomRootNode->addChild(painting3Transform);
    painting3Transform->addChild(painting3);

    roomRootNode->addChild(painting4Transform);
    painting4Transform->addChild(painting4);

    roomRootNode->addChild(painting5Transform);
    painting5Transform->addChild(painting5);

    roomRootNode->addChild(painting6Transform);
    painting6Transform->addChild(painting6);

    roomRootNode->addChild(painting7Transform);
    painting7Transform->addChild(painting7);

    roomRootNode->addChild(painting8Transform);
    painting8Transform->addChild(painting8);

    roomRootNode->addChild(painting9Transform);
    painting9Transform->addChild(painting9);

    // Apply Transforms

    robotHeadTransform->setTranslationTo(0,1.50,0);
    robotHeadTransform->setColor(1,0,0);
    robotHeadTransform->setScaleTo(1,1.25,1);

    robotTorsoTransform->setColor(1,1,0);
    //robotTorsoTransform->setTranslationTo(0,-12,0);
    robotTorsoTransform->setTranslationTo(25,-12,90);
    //robotTorsoTransform->setTranslationTo(0,-12,0);
    robotTorsoTransform->setScaleTo(4,4,4);
    robotTorsoTransform->setRotationTo(0,180,0);

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

    const unsigned int roomScale = 100 ;
    unsigned int paintingScale = 15 ;
    int roomDepthFromCentre = 25 ;

    // Room transforms
    roomFloorTransform->setTranslationTo(0,-roomDepthFromCentre,0);
    roomFloorTransform->setScaleTo(roomScale,1,roomScale*2);

    roomCeilingTransform->setTranslationTo(0,roomDepthFromCentre,0);
    roomCeilingTransform->setScaleTo(roomScale,1,roomScale*2);
    roomCeilingTransform->setRotationTo(180,0,0);

    roomLeftWallTransform->setTranslationTo(-50,roomDepthFromCentre,0);
    roomLeftWallTransform->setScaleTo(roomScale,1,roomScale*2);
    roomLeftWallTransform->setRotationTo(0,0,-90);

    roomRightWallTransform->setTranslationTo(50,roomDepthFromCentre,0);
    roomRightWallTransform->setScaleTo(roomScale,1,roomScale*2);
    roomRightWallTransform->setRotationTo(0,0,90);

    roomFrontWallTransform->setTranslationTo(0,0,60);
    roomFrontWallTransform->setScaleTo(roomScale,1,roomScale*.5);
    roomFrontWallTransform->setRotationTo(90,0,0);

    roomBackWallTransform->setTranslationTo(0,roomDepthFromCentre,-40);
    roomBackWallTransform->setScaleTo(roomScale,1,roomScale);
    roomBackWallTransform->setRotationTo(90,0,0);

    roomFrontWallLeftDoorTransform->setTranslationTo(20,-5,65);
    roomFrontWallLeftDoorTransform->setRotationTo(90,0,0);
    roomFrontWallLeftDoorTransform->setScaleTo(roomScale/8.5,1,2*roomScale/5.75);

    roomFrontWallRightDoorTransform->setTranslationTo(31.5,-5,65);
    roomFrontWallRightDoorTransform->setRotationTo(90,0,0);
    roomFrontWallRightDoorTransform->setScaleTo(roomScale/8.5,1,2*roomScale/5.75);

    //painting transforms

    painting1Transform->setTranslationTo(-30,0,-35);
    painting1Transform->setScaleTo(paintingScale,1,paintingScale*2);
    painting1Transform->setRotationTo(90,0,0);

    painting2Transform->setTranslationTo( 0,0,-35);
    painting2Transform->setScaleTo(paintingScale,1,paintingScale*2);
    painting2Transform->setRotationTo(90,0,0);

    painting3Transform->setTranslationTo( 30,0,-35);
    painting3Transform->setScaleTo(paintingScale,1,paintingScale*2);
    painting3Transform->setRotationTo(90,0,0);

    painting4Transform->setTranslationTo( 45,0,-10);
    painting4Transform->setScaleTo(paintingScale,1,paintingScale*2);
    painting4Transform->setRotationTo(90,0,90);

    painting5Transform->setTranslationTo( 45,0,15);
    painting5Transform->setScaleTo(paintingScale,1,paintingScale*2);
    painting5Transform->setRotationTo(90,0,90);

    painting6Transform->setTranslationTo( 45,0,45);
    painting6Transform->setScaleTo(paintingScale,1,paintingScale*2);
    painting6Transform->setRotationTo(90,0,90);

    painting7Transform->setTranslationTo( -45,0,-10);
    painting7Transform->setScaleTo(paintingScale,1,paintingScale*2);
    painting7Transform->setRotationTo(90,0,-90);

    painting8Transform->setTranslationTo( -45,0,15);
    painting8Transform->setScaleTo(paintingScale,1,paintingScale*2);
    painting8Transform->setRotationTo(90,0,-90);

    painting9Transform->setTranslationTo( -45,0,45);
    painting9Transform->setScaleTo(paintingScale,1,paintingScale*2);
    painting9Transform->setRotationTo(90,0,-90);

    // For testing
    // robotController->moveRobotTo(-10,40);
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

RobotController *GLRenderer::getRobotController()
{
    return robotController;
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

    Factory::cameraController->repositionCamera();

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
   glViewport(0,0,width,height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(110,width/height,1,500);
   glMatrixMode(GL_MODELVIEW);
}

void GLRenderer::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();

    double modelview[16], projection[16];
    int viewport[4];
    int x = event->x(), y = event->y();
    double objx = 0, objy=0, objz=0;
    float z = 1;

    /*Read the projection, modelview and viewport matrices
    using the glGet functions.*/
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    glGetIntegerv( GL_VIEWPORT, viewport );

    //Read the window z value from the z-buffer
    glReadPixels( x, viewport[3]-y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z );

    //Use the gluUnProject to get the world co-ordinates of
    //the point the user clicked and save in objx, objy, objz.
    gluUnProject( x, viewport[3]-y, z, modelview, projection, viewport, &objx, &objy, &objz );

    std::cout << "Clicked " << objx << " , " << objz << std::endl ;
    robotController->moveRobotTo(objx,objz);
}

/*
    Handle key press events
*/
void GLRenderer::keyPressEvent(QKeyEvent *keyevent)
{
    // Change the viewpoint b/w Robot and Room corner
    if( keyevent->key() == Qt::Key_C )
    {
        if( false == cameraController->isCameraFollowingRobot() )
        {
            cameraController->setCameraFollowingRobotStatus(true);
            robotRootNode->setTraversal(false);
        }

        else
        {
            cameraController->setCameraFollowingRobotStatus(false);
            robotRootNode->setTraversal(true);
        }
    }

    else if( keyevent->key() == Qt::Key_O )
    {
        doorController->openDoor();
    }

    else if( keyevent->key() == Qt::Key_V )
    {
        cameraController->moveCameraToNextViewPoint();
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
