#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "Node.h"

class LightSource : public ScenegraphNode
{
public:
    LightSource();
    void traverseNode();
    void setLightPosition(float,float,float);
    void setLightMovement(bool);
    void setLight(bool);

private:

    float lightPositionX;
    float lightPositionY;
    float lightPositionZ;
    bool  isLightMovementEnabled;
    bool  isLightEnabled;
};

#endif // LIGHTSOURCE_H
