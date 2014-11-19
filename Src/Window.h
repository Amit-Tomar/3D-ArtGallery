#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "GLRenderer.h"

class GLRenderer;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();
    GLRenderer *glWidget;

protected:
    void keyPressEvent(QKeyEvent *event);

private:
};

#endif
