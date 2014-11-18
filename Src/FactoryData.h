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

class Transform;

namespace Factory
{
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
extern Transform       *roomBackWallTransform       ;
extern Transform       *roomCeilingTransform        ;

extern BuildingBlock   *roomFloor                   ;
extern BuildingBlock   *roomLeftWall                ;
extern BuildingBlock   *roomRightWal                ;
extern BuildingBlock   *roomFrontWal                ;
extern BuildingBlock   *roomBackWall                ;
extern BuildingBlock   *roomCeiling                 ;

//extern RobotController *robotController           ;
}

#endif // FACTORYDATA_H
