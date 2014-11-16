#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QPushButton>
#include "GLRenderer.h"
#include "Window.h"
#include <QFileDialog>
#include "Node.h"
#include "Transform.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //initialize glut
    QApplication app(argc, argv);
    Window window;
    window.setGeometry(0,0,800,600);
    window.show();
    return app.exec();
}
