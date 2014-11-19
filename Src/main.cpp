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

using namespace Factory;

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //initialize glut
    QApplication app(argc, argv);
    window = new Window();
    window->setGeometry(0,0,1024,768);
    window->showMaximized();
    return app.exec();
}
