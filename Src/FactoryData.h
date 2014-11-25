#ifndef FACTORYDATA_H
#define FACTORYDATA_H

#include "RobotTorsoModel.h"
#include "RoomModel.h"
#include "RobotArmBottom.h"
#include "RobotArmTop.h"
#include "RobotLegBottom.h"
#include "RobotLegTop.h"
#include "RobotHead.h"
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

class Transform;
class RobotTorsoModel;
class Camera;
class Window;
class CameraController;
class DoorController;
class AudioPlayer;

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

extern Transform       *painting1Transform          ;
extern Transform       *painting2Transform          ;
extern Transform       *painting3Transform          ;
extern Transform       *painting4Transform          ;
extern Transform       *painting5Transform          ;
extern Transform       *painting6Transform          ;
extern Transform       *painting7Transform          ;
extern Transform       *painting8Transform          ;
extern Transform       *painting9Transform          ;

extern Transform       *roomFrontWallLeftDoorTransform  ;
extern Transform       *roomFrontWallRightDoorTransform ;

extern BuildingBlock    *roomFrontWallLeftDoor       ;
extern BuildingBlock    *roomFrontWallRightDoor      ;
extern BuildingBlock    *roomFloor                   ;
extern BuildingBlock    *roomLeftWall                ;
extern BuildingBlock    *roomRightWall               ;
extern BuildingBlock    *roomFrontWall               ;
extern BuildingBlock    *roomFrontWallIn             ;
extern BuildingBlock    *roomBackWall                ;
extern BuildingBlock    *roomCeiling                 ;
extern BuildingBlock    *painting1                   ;
extern BuildingBlock    *painting2                   ;
extern BuildingBlock    *painting3                   ;
extern BuildingBlock    *painting4                   ;
extern BuildingBlock    *painting5                   ;
extern BuildingBlock    *painting6                   ;
extern BuildingBlock    *painting7                   ;
extern BuildingBlock    *painting8                   ;
extern BuildingBlock    *painting9                   ;
extern AudioPlayer      *audioPlayer                 ;
extern CameraController *cameraController            ;
extern PaintingFrame     *painting1Frame              ;
extern PaintingFrame     *painting2Frame              ;
extern PaintingFrame     *painting3Frame              ;
extern PaintingFrame     *painting4Frame              ;
extern PaintingFrame     *painting5Frame              ;
extern PaintingFrame     *painting6Frame              ;
extern PaintingFrame     *painting7Frame              ;
extern PaintingFrame     *painting8Frame              ;
extern PaintingFrame     *painting9Frame              ;
}





#endif // FACTORYDATA_H
