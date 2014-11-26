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
    glutSolidCylinder(5,10,100,10);
}
