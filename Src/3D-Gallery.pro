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
    CameraController.h \
    AudioPlayer.h \
    DoorController.h \
    PaintingsController.h \
    PaintingFrame.h \
    Obstacle.h \
    VideoPlayer.h



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
    CameraController.cpp \
    BuildingBlock.cpp \
    AudioPlayer.cpp \
    DoorController.cpp \
    PaintingsController.cpp \
    PaintingFrame.cpp \
    Obstacle.cpp \
    VideoPlayer.cpp


QT           += opengl widgets multimedia multimediawidgets

LIBS += -lGL -lGLU -lGLEW -lglut -lSOIL

OTHER_FILES += \
    vshader.glsl \
    fshader.glsl

INSTALLS += ../Build

