#ifndef FACTORYDATA_H
#define FACTORYDATA_H

#include "RobotTorseModel.h"
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

namespace Factory
{
extern GroupNode       *scenegraphRootNode   ;
extern LightSource     *centralLightSource   ;
extern Camera          *camera               ;
extern GroupNode       *robotRootNode        ;
extern GroupNode       *roomRootNode         ;
extern Transform       *robotTorsoTransform  ;
extern Transform       *roomCentralTransform ;
extern RoomModel       *roomModel            ;
extern RobotTorsoModel *robotTorso           ;
extern RobotLegTop     *robotLeftLegTop      ;
extern RobotLegTop     *robotRightLegTop     ;
extern RobotLegBottom  *robotLeftLegBottom   ;
extern RobotLegBottom  *robotRightLegBottom  ;
extern RobotArmTop     *robotRightArmTop     ;
extern RobotArmTop     *robotLeftArmTop      ;
extern RobotArmBottom  *robotRightBottom     ;
extern RobotArmBottom  *robotLeftBottom      ;
extern RobotHead       *robotHead            ;
extern Transform       *robotLeftThighTransform     ;
extern Transform       *robotRightThighTransform    ;
extern Transform       *robotLeftKneeTransform      ;
extern Transform       *robotRightKneeTransform     ;
extern Transform       *robotLeftShoulderTransform  ;
extern Transform       *robotRightShoulderTransform ;
extern Transform       *robotLeftElbowTransform     ;
extern Transform       *robotRightElbowTransform    ;
extern Transform       *robotHeadTransform          ;
//extern RobotController *robotController             ;
}

#endif // FACTORYDATA_H
