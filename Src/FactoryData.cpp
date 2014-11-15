#include "FactoryData.h"

namespace Factory
{
GroupNode       *scenegraphRootNode          = new GroupNode() ;
LightSource     *centralLightSource          = new LightSource();
Camera          *camera                      = new Camera();
GroupNode       *robotRootNode               = new GroupNode() ;
GroupNode       *roomRootNode                = new GroupNode() ;
Transform       *robotTorsoTransform         = new Transform();
Transform       *roomCentralTransform        = new Transform();
RoomModel       *roomModel                   = new RoomModel();
RobotTorsoModel *robotTorso                  = new RobotTorsoModel();
RobotLegTop     *robotLeftLegTop             = new RobotLegTop();
RobotLegTop     *robotRightLegTop            = new RobotLegTop();
RobotLegBottom  *robotLeftLegBottom          = new RobotLegBottom();
RobotLegBottom  *robotRightLegBottom         = new RobotLegBottom();
RobotArmTop     *robotRightArmTop            = new RobotArmTop();
RobotArmTop     *robotLeftArmTop             = new RobotArmTop();
RobotArmBottom  *robotRightBottom            = new RobotArmBottom();
RobotArmBottom  *robotLeftBottom             = new RobotArmBottom();
RobotHead       *robotHead                   = new RobotHead();
Transform       *robotLeftThighTransform     = new Transform();
Transform       *robotRightThighTransform    = new Transform();
Transform       *robotLeftKneeTransform      = new Transform();
Transform       *robotRightKneeTransform     = new Transform();
Transform       *robotLeftShoulderTransform  = new Transform();
Transform       *robotRightShoulderTransform = new Transform();
Transform       *robotLeftElbowTransform     = new Transform();
Transform       *robotRightElbowTransform    = new Transform();
Transform       *robotHeadTransform          = new Transform();
}
