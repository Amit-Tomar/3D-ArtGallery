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
    glutSolidCube(10);
}
