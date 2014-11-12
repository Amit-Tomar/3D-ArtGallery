#include "LightSource.h"

LightSource::LightSource()
{
    setLightPosition(0.0,0.0,0.0);
    isLightMovementEnabled = false;
    isLightEnabled = true;
}

void LightSource::traverseNode()
{

}

void LightSource::setLightPosition(float lightPositionX, float lightPositionY, float lightPositionZ)
{
    this->lightPositionX = lightPositionX;
    this->lightPositionY = lightPositionY;
    this->lightPositionZ = lightPositionZ;
}

void LightSource::setLightMovement(bool lightMovementEnabled)
{
    this->isLightMovementEnabled = lightMovementEnabled;
}

void LightSource::setLight(bool isLightEnabled)
{
    this->isLightEnabled = isLightEnabled;
}
