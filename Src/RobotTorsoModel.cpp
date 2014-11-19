#include "RobotTorsoModel.h"

RobotTorsoModel::RobotTorsoModel()
{
}

void RobotTorsoModel::traverseNode()
{
        renderTorso();
}

void RobotTorsoModel::renderTorso()
{
    float matrix[16];
    glGetFloatv(GL_MODELVIEW_MATRIX,matrix);

    float invOut[16];
    float inv[16], det;
    int i;

    inv[0] = matrix[5]  * matrix[10] * matrix[15] -
             matrix[5]  * matrix[11] * matrix[14] -
             matrix[9]  * matrix[6]  * matrix[15] +
             matrix[9]  * matrix[7]  * matrix[14] +
             matrix[13] * matrix[6]  * matrix[11] -
             matrix[13] * matrix[7]  * matrix[10];

    inv[4] = -matrix[4]  * matrix[10] * matrix[15] +
              matrix[4]  * matrix[11] * matrix[14] +
              matrix[8]  * matrix[6]  * matrix[15] -
              matrix[8]  * matrix[7]  * matrix[14] -
              matrix[12] * matrix[6]  * matrix[11] +
              matrix[12] * matrix[7]  * matrix[10];

    inv[8] = matrix[4]  * matrix[9] * matrix[15] -
             matrix[4]  * matrix[11] * matrix[13] -
             matrix[8]  * matrix[5] * matrix[15] +
             matrix[8]  * matrix[7] * matrix[13] +
             matrix[12] * matrix[5] * matrix[11] -
             matrix[12] * matrix[7] * matrix[9];

    inv[12] = -matrix[4]  * matrix[9] * matrix[14] +
               matrix[4]  * matrix[10] * matrix[13] +
               matrix[8]  * matrix[5] * matrix[14] -
               matrix[8]  * matrix[6] * matrix[13] -
               matrix[12] * matrix[5] * matrix[10] +
               matrix[12] * matrix[6] * matrix[9];

    inv[1] = -matrix[1]  * matrix[10] * matrix[15] +
              matrix[1]  * matrix[11] * matrix[14] +
              matrix[9]  * matrix[2] * matrix[15] -
              matrix[9]  * matrix[3] * matrix[14] -
              matrix[13] * matrix[2] * matrix[11] +
              matrix[13] * matrix[3] * matrix[10];

    inv[5] = matrix[0]  * matrix[10] * matrix[15] -
             matrix[0]  * matrix[11] * matrix[14] -
             matrix[8]  * matrix[2] * matrix[15] +
             matrix[8]  * matrix[3] * matrix[14] +
             matrix[12] * matrix[2] * matrix[11] -
             matrix[12] * matrix[3] * matrix[10];

    inv[9] = -matrix[0]  * matrix[9] * matrix[15] +
              matrix[0]  * matrix[11] * matrix[13] +
              matrix[8]  * matrix[1] * matrix[15] -
              matrix[8]  * matrix[3] * matrix[13] -
              matrix[12] * matrix[1] * matrix[11] +
              matrix[12] * matrix[3] * matrix[9];

    inv[13] = matrix[0]  * matrix[9] * matrix[14] -
              matrix[0]  * matrix[10] * matrix[13] -
              matrix[8]  * matrix[1] * matrix[14] +
              matrix[8]  * matrix[2] * matrix[13] +
              matrix[12] * matrix[1] * matrix[10] -
              matrix[12] * matrix[2] * matrix[9];

    inv[2] = matrix[1]  * matrix[6] * matrix[15] -
             matrix[1]  * matrix[7] * matrix[14] -
             matrix[5]  * matrix[2] * matrix[15] +
             matrix[5]  * matrix[3] * matrix[14] +
             matrix[13] * matrix[2] * matrix[7] -
             matrix[13] * matrix[3] * matrix[6];

    inv[6] = -matrix[0]  * matrix[6] * matrix[15] +
              matrix[0]  * matrix[7] * matrix[14] +
              matrix[4]  * matrix[2] * matrix[15] -
              matrix[4]  * matrix[3] * matrix[14] -
              matrix[12] * matrix[2] * matrix[7] +
              matrix[12] * matrix[3] * matrix[6];

    inv[10] = matrix[0]  * matrix[5] * matrix[15] -
              matrix[0]  * matrix[7] * matrix[13] -
              matrix[4]  * matrix[1] * matrix[15] +
              matrix[4]  * matrix[3] * matrix[13] +
              matrix[12] * matrix[1] * matrix[7] -
              matrix[12] * matrix[3] * matrix[5];

    inv[14] = -matrix[0]  * matrix[5] * matrix[14] +
               matrix[0]  * matrix[6] * matrix[13] +
               matrix[4]  * matrix[1] * matrix[14] -
               matrix[4]  * matrix[2] * matrix[13] -
               matrix[12] * matrix[1] * matrix[6] +
               matrix[12] * matrix[2] * matrix[5];

    inv[3] = -matrix[1] * matrix[6] * matrix[11] +
              matrix[1] * matrix[7] * matrix[10] +
              matrix[5] * matrix[2] * matrix[11] -
              matrix[5] * matrix[3] * matrix[10] -
              matrix[9] * matrix[2] * matrix[7] +
              matrix[9] * matrix[3] * matrix[6];

    inv[7] = matrix[0] * matrix[6] * matrix[11] -
             matrix[0] * matrix[7] * matrix[10] -
             matrix[4] * matrix[2] * matrix[11] +
             matrix[4] * matrix[3] * matrix[10] +
             matrix[8] * matrix[2] * matrix[7] -
             matrix[8] * matrix[3] * matrix[6];

    inv[11] = -matrix[0] * matrix[5] * matrix[11] +
               matrix[0] * matrix[7] * matrix[9] +
               matrix[4] * matrix[1] * matrix[11] -
               matrix[4] * matrix[3] * matrix[9] -
               matrix[8] * matrix[1] * matrix[7] +
               matrix[8] * matrix[3] * matrix[5];

    inv[15] = matrix[0] * matrix[5] * matrix[10] -
              matrix[0] * matrix[6] * matrix[9] -
              matrix[4] * matrix[1] * matrix[10] +
              matrix[4] * matrix[2] * matrix[9] +
              matrix[8] * matrix[1] * matrix[6] -
              matrix[8] * matrix[2] * matrix[5];

    det = matrix[0] * inv[0] + matrix[1] * inv[4] + matrix[2] * inv[8] + matrix[3] * inv[12];

    if (det == 0)
    {
        std::cerr << "Determinanat value is 0" << std::endl;
    }

    else
    {
        det = 1.0 / det;

        for (i = 0; i < 16; i++)
        {
            invOut[i] = inv[i] * det;
            //std::cout << "Matrix : " << inv[i] << std::endl ;
        }
    }

    //std::cout << "\n\n\n\n " << std::endl ;

  //  std::cout << "Co : " << matrix[12] << " : " << matrix[13] << " : "  << matrix[14] << std::endl;

   //glPushMatrix();
   //  glMatrixMode(GL_MODELVIEW);
   //  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   //  glLoadIdentity();
   //  gluLookAt(matrix[12],matrix[13],matrix[14],0,0,0,0,1,0);
   //  //gluLookAt(0,0,5,0,0,0,0,1,0);
   //gluLookAt(0,10,10,0,0,0,0,1,0);
   // glPopMatrix();
   //  glMatrixMode(GL_MODELVIEW);

//    gluLookAt(0,10,10,0,0,0,0,1,0);

    glPushMatrix();
    glScalef(1,2,1);
    glutSolidCube(1);
    glPopMatrix();
   }
