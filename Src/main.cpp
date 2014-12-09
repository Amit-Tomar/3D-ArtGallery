#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QPushButton>
#include "GLRenderer.h"
#include "Window.h"
#include <QFileDialog>
#include "Node.h"
#include "Transform.h"
#include "FactoryData.h"
#include "VideoPlayer.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //initialize glut
    QApplication app(argc, argv);
    Factory::generateAllObjects();
    Factory::window = new Window();
    Factory::window->setGeometry(0,0,1024,768);
    Factory::window->showMaximized();
    Factory::videoPlayer = new VideoPlayer(Factory::window);
    Factory::videoPlayer->setGeometry(610,320,150,100);
    //Factory::videoPlayer->show();
    return app.exec();
}
