#include "FactoryData.h"

namespace Factory
{
Window          *window                      = NULL;
GroupNode       *scenegraphRootNode          = NULL;
LightSource     *centralLightSource          = NULL;
Camera          *camera                      = NULL;
GroupNode       *robotRootNode               = NULL;
GroupNode       *roomRootNode                = NULL;
RoomModel       *roomModel                   = NULL;
RobotTorsoModel *robotTorso                  = NULL;
RobotLegTop     *robotLeftLegTop             = NULL;
RobotLegTop     *robotRightLegTop            = NULL;
RobotLegBottom  *robotLeftLegBottom          = NULL;
RobotLegBottom  *robotRightLegBottom         = NULL;
RobotArmTop     *robotRightArmTop            = NULL;
RobotArmTop     *robotLeftArmTop             = NULL;
RobotArmBottom  *robotRightBottom            = NULL;
RobotArmBottom  *robotLeftBottom             = NULL;
RobotHead       *robotHead                   = NULL;
RobotShoe       *robotLeftShoe               = NULL;
RobotShoe       *robotRightShoe              = NULL;
RobotHat        *robotHat                    = NULL;
Transform       *robotLeftThighTransform     = NULL;
Transform       *robotRightThighTransform    = NULL;
Transform       *robotLeftKneeTransform      = NULL;
Transform       *robotRightKneeTransform     = NULL;
Transform       *robotLeftShoulderTransform  = NULL;
Transform       *robotRightShoulderTransform = NULL;
Transform       *robotLeftElbowTransform     = NULL;
Transform       *robotRightElbowTransform    = NULL;
Transform       *robotHeadTransform          = NULL;
Transform       *robotTorsoTransform         = NULL;
Transform       *roomCentralTransform        = NULL;
Transform       *robotLeftShoeTransform      = NULL;
Transform       *robotRightShoeTransform     = NULL;
Transform       *robotHatTransform           = NULL;
Transform       *roomFloorTransform          = NULL;
Transform       *roomLeftWallTransform       = NULL;
Transform       *roomRightWallTransform      = NULL;
Transform       *roomFrontWallTransform      = NULL;
Transform       *roomFrontWallInTransform    = NULL;
Transform       *roomBackWallTransform       = NULL;
Transform       *roomCeilingTransform        = NULL;


Transform       *roomFrontWallLeftDoorTransform  = NULL;
Transform       *roomFrontWallRightDoorTransform = NULL;
Transform       *obstacleTransform               = NULL;

BuildingBlock    *roomFrontWallLeftDoor       = NULL;
BuildingBlock    *roomFrontWallRightDoor      = NULL;
BuildingBlock    *roomFloor                   = NULL;
BuildingBlock    *roomLeftWall                = NULL;
BuildingBlock    *roomRightWall               = NULL;
BuildingBlock    *roomFrontWall               = NULL;
BuildingBlock    *roomFrontWallIn             = NULL;
BuildingBlock    *roomBackWall                = NULL;
BuildingBlock    *roomCeiling                 = NULL;

std::vector<Transform*> paintingTransformList;
std::vector<BuildingBlock*> paintingsList;
std::vector<PaintingFrame*> paintingFramesList;

CameraController    *cameraController         = NULL;
PaintingsController * paintingController      = NULL;
RoomController      * roomController          = NULL;
AudioPlayer         *audioPlayer              = NULL;
VideoPlayer         *videoPlayer              = NULL;
Obstacle            *obstacle                 = NULL;

void generateAllObjects()
{
    window                      = NULL;
    scenegraphRootNode          = new GroupNode() ;
    centralLightSource          = new LightSource();
    camera                      = new Camera();
    robotRootNode               = new GroupNode() ;
    roomRootNode                = new GroupNode() ;
    roomModel                   = new RoomModel();
    robotTorso                  = new RobotTorsoModel();
    robotLeftLegTop             = new RobotLegTop();
    robotRightLegTop            = new RobotLegTop();
    robotLeftLegBottom          = new RobotLegBottom();
    robotRightLegBottom         = new RobotLegBottom();
    robotRightArmTop            = new RobotArmTop();
    robotLeftArmTop             = new RobotArmTop();
    robotRightBottom            = new RobotArmBottom();
    robotLeftBottom             = new RobotArmBottom();
    robotHead                   = new RobotHead();
    robotLeftShoe               = new RobotShoe();
    robotRightShoe              = new RobotShoe();
    robotHat                    = new RobotHat();
    robotLeftThighTransform     = new Transform();
    robotRightThighTransform    = new Transform();
    robotLeftKneeTransform      = new Transform();
    robotRightKneeTransform     = new Transform();
    robotLeftShoulderTransform  = new Transform();
    robotRightShoulderTransform = new Transform();
    robotLeftElbowTransform     = new Transform();
    robotRightElbowTransform    = new Transform();
    robotHeadTransform          = new Transform();
    robotTorsoTransform         = new Transform();
    roomCentralTransform        = new Transform();
    robotLeftShoeTransform      = new Transform();
    robotRightShoeTransform     = new Transform();
    robotHatTransform           = new Transform();
    roomFloorTransform          = new Transform();
    roomLeftWallTransform       = new Transform();
    roomRightWallTransform      = new Transform();
    roomFrontWallTransform      = new Transform();
    roomFrontWallInTransform    = new Transform();
    roomBackWallTransform       = new Transform();
    roomCeilingTransform        = new Transform();

    for( int i = 0 ; i < 10 ; ++i )
        paintingTransformList.push_back( new Transform() );

    roomFrontWallLeftDoorTransform      = new Transform();
    roomFrontWallRightDoorTransform     = new Transform();
    obstacleTransform                   = new Transform();

    roomFrontWallLeftDoor       = new BuildingBlock("../Textures/doorLeft.png");
    roomFrontWallRightDoor      = new BuildingBlock("../Textures/doorRight.png");
    roomFloor                   = new BuildingBlock("../Textures/floor1.png");
    roomLeftWall                = new BuildingBlock("../Textures/wall1Long.png",12);
    roomRightWall               = new BuildingBlock("../Textures/wall1Long.png",12);
    roomFrontWall               = new BuildingBlock("../Textures/wall3_noDoor.png");
    roomFrontWallIn             = new BuildingBlock("../Textures/wall3Mirror.png");
    roomBackWall                = new BuildingBlock("../Textures/wall1.png",5);
    roomCeiling                 = new BuildingBlock("../Textures/wall2.png",12);

    for( int i = 0 ; i < 10 ; ++i )
        paintingFramesList.push_back( new PaintingFrame());

    cameraController            = new CameraController();
    paintingController          = new PaintingsController();
    audioPlayer                 = new AudioPlayer();

    obstacle                    = new Obstacle();
    roomController              = new RoomController();

    QString dir = QFileDialog::getExistingDirectory(NULL, QObject::tr("Open Directory"), "./", QFileDialog::ShowDirsOnly);
    QStringList nameFilter(QString::fromStdString("*.png"));
    QDir directory(dir);
    QStringList txtFilesAndDirectories = directory.entryList(nameFilter);

    for( int i = 0 ; i < txtFilesAndDirectories.length() ; ++ i )
    {
        std::string fileName = dir.toStdString()+ "/"  +(txtFilesAndDirectories[i].toStdString()) ;
        std::cout << fileName << std::endl;
        paintingsList.push_back( new BuildingBlock(fileName));
    }

    for( int i = txtFilesAndDirectories.length() ; i < 10 ; ++i )
        paintingsList.push_back( new BuildingBlock("../Paintings/painting1.png"));
}

}
