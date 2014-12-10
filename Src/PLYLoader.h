#ifndef MODEL_PLY_H
#define MODEL_PLY_H

#include <stdio.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <string>
#include <cstdlib>

class Model_PLY
{
public:

    Model_PLY();

    int Load(char *filename);
    void Draw();
    float* calculateNormal( float *coord1, float *coord2, float *coord3 );

    float* Faces_Triangles;
    float* Faces_Quads;
    float* Vertex_Buffer;
    float* Normals;

    int TotalConnectedTriangles;
    int TotalConnectedQuads;
    int TotalConnectedPoints;
    int TotalFaces;
};

#endif // MODEL_PLY_H
