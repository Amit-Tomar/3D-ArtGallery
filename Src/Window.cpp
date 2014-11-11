#include <QtWidgets>

#include "GLRenderer.h"
#include "Window.h"

Window::Window()
{
    glWidget = new GLRenderer;

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(glWidget);
    setLayout(mainLayout);

    setWindowTitle(tr("3-D Art Gallery"));
}

void Window::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}
