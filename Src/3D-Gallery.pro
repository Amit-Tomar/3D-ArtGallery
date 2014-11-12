HEADERS       = \
                GLRenderer.h \
                Window.h \
    Quaternions.h \
    Transform.h \
    Node.h \
    LightSource.h \
    Camera.h \
    GroupNode.h \
    RobotTorseModel.h

    TransformTypes.h \



SOURCES       = main.cpp \
                Window.cpp \
                GLRenderer.cpp \
    Quaternions.cpp \
    Transform.cpp \
    Node.cpp \
    LightSource.cpp \
    Camera.cpp \
    GroupNode.cpp \
    RobotTorseModel.cpp


QT           += opengl widgets

LIBS += -lassimp -lGL -lGLU -lGLEW -lglut

OTHER_FILES += \
    vshader.glsl \
    fshader.glsl

INSTALLS += ../Build

