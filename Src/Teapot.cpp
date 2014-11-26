#include "Teapot.h"

Teapot::Teapot()
{
}

void Teapot::traverseNode()
{
    renderTeapot();
}

void Teapot::renderTeapot()
{
    glutSolidCylinder(3,5,100,10);
}
