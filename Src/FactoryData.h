#ifndef FACTORYDATA_H
#define FACTORYDATA_H

#include "RobotTorsoModel.h"
#include "RoomModel.h"
#include "RobotArmBottom.h"
#include "RobotArmTop.h"
#include "RobotLegBottom.h"
#include "RobotLegTop.h"
#include "RobotHead.h"
#include <qfiledialog.h>
#include <LightSource.h>
#include <Camera.h>
#include <GroupNode.h>
#include <Transform.h>
#include <RobotController.h>
#include <RobotShoe.h>
#include <BuildingBlock.h>
#include "Window.h"
#include "CameraController.h"
#include "PaintingFrame.h"
#include "AudioPlayer.h"
#include "Obstacle.h"
#include "PaintingsController.h"
#include "VideoPlayer.h"

class Transform;
class RobotTorsoModel;
class Camera;
class Window;
class CameraController;
class DoorController;
class AudioPlayer;
class PaintingsController;

namespace Factory
{
extern Window          *window                      ;
extern GroupNode       *scenegraphRootNode          ;
extern LightSource     *centralLightSource          ;
extern Camera          *camera                      ;
extern GroupNode       *robotRootNode               ;
extern GroupNode       *roomRootNode                ;
extern RoomModel       *roomModel                   ;
extern RobotTorsoModel *robotTorso                  ;
extern RobotLegTop     *robotLeftLegTop             ;
extern RobotLegTop     *robotRightLegTop            ;
extern RobotLegBottom  *robotLeftLegBottom          ;
extern RobotLegBottom  *robotRightLegBottom         ;
extern RobotArmTop     *robotRightArmTop            ;
extern RobotArmTop     *robotLeftArmTop             ;
extern RobotArmBottom  *robotRightBottom            ;
extern RobotArmBottom  *robotLeftBottom             ;
extern RobotHead       *robotHead                   ;
extern RobotShoe       *robotLeftShoe               ;
extern RobotShoe       *robotRightShoe              ;
extern Transform       *robotLeftThighTransform     ;
extern Transform       *robotRightThighTransform    ;
extern Transform       *robotLeftKneeTransform      ;
extern Transform       *robotRightKneeTransform     ;
extern Transform       *robotLeftShoulderTransform  ;
extern Transform       *robotRightShoulderTransform ;
extern Transform       *robotLeftElbowTransform     ;
extern Transform       *robotRightElbowTransform    ;
extern Transform       *robotHeadTransform          ;
extern Transform       *robotTorsoTransform         ;
extern Transform       *roomCentralTransform        ;
extern Transform       *robotLeftShoeTransform      ;
extern Transform       *robotRightShoeTransform     ;
extern Transform       *roomFloorTransform          ;
extern Transform       *roomLeftWallTransform       ;
extern Transform       *roomRightWallTransform      ;
extern Transform       *roomFrontWallTransform      ;
extern Transform       *roomFrontWallInTransform    ;
extern Transform       *roomBackWallTransform       ;
extern Transform       *roomCeilingTransform        ;


extern Transform       *obstacleTransform             ;

extern Transform       *roomFrontWallLeftDoorTransform  ;
extern Transform       *roomFrontWallRightDoorTransform ;

extern AudioPlayer          *audioPlayer              ;
extern VideoPlayer          *videoPlayer              ;
extern CameraController     *cameraController         ;
extern Obstacle             *obstacle                 ;
extern PaintingsController  * paintingController      ;


extern BuildingBlock    *roomFrontWallLeftDoor       ;
extern BuildingBlock    *roomFrontWallRightDoor      ;
extern BuildingBlock    *roomFloor                   ;
extern BuildingBlock    *roomLeftWall                ;
extern BuildingBlock    *roomRightWall               ;
extern BuildingBlock    *roomFrontWall               ;
extern BuildingBlock    *roomFrontWallIn             ;
extern BuildingBlock    *roomBackWall                ;
extern BuildingBlock    *roomCeiling                 ;

extern std::vector<Transform*> paintingTransformList;
extern std::vector<BuildingBlock*> paintingsList;
extern std::vector<PaintingFrame*> paintingFramesList;

void generateAllObjects();
}

#endif // FACTORYDATA_H
