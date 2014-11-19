HEADERS       = \
                GLRenderer.h \
                Window.h \
    Quaternions.h \
    Transform.h \
    Node.h \
    LightSource.h \
    Camera.h \
    GroupNode.h \
    RoomModel.h \
    RobotArmTop.h \
    RobotArmBottom.h \
    RobotLegTop.h \
    RobotLegBottom.h \
    RobotHead.h \
    RobotController.h \
    FactoryData.h \
    ModelRenderer.h \
    RobotShoe.h \
    RobotTorsoModel.h \
    BuildingBlock.h \
    TransformTypes.h \
    CameraController.h



SOURCES       = main.cpp \
                Window.cpp \
                GLRenderer.cpp \
    Quaternions.cpp \
    Transform.cpp \
    Node.cpp \
    LightSource.cpp \
    Camera.cpp \
    GroupNode.cpp \
    RoomModel.cpp \
    RobotArmTop.cpp \
    RobotArmBottom.cpp \
    RobotLegTop.cpp \
    RobotLegBottom.cpp \
    RobotHead.cpp \
    RobotController.cpp \
    FactoryData.cpp \
    ModelRenderer.cpp \
    RobotShoe.cpp \
    RobotTorsoModel.cpp \
    BuildingBlock.cpp \
    CameraController.cpp


QT           += opengl widgets

LIBS += -lGL -lGLU -lGLEW -lglut

OTHER_FILES += \
    vshader.glsl \
    fshader.glsl

INSTALLS += ../Build

