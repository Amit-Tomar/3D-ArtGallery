#include "BuildingBlock.h"

GLfloat vertices[] =  { -0.5f, 0.0f, 0.5f,   0.5f, 0.0f, 0.5f,   0.5f, 0.0f, -0.5f,  -0.5f, 0.0f, -0.5f};
GLfloat texcoords[] = { 0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0};
GLubyte cubeIndices[24] = {0,1,2,3};

BuildingBlock::BuildingBlock(std::string path)
{
    textureImagePath = path;
    textureBinded = false;

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    textureImagePath = path;
}

void BuildingBlock::traverseNode()
{
    renderBuildingBlock();
}

void BuildingBlock::renderBuildingBlock()
{
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glFrontFace(GL_CW);

    if( !textureBinded )
    {
        textureId = SOIL_load_OGL_texture
        (
            textureImagePath.c_str(),
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
        );

        if( 0 == textureId )
            std::cout << "SOIL loading error : "<< SOIL_last_result() << " while using file " << textureImagePath << std::endl ;

        textureBinded = true;
    }

    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glColor3f (1.0,1.0,1.0);

    glBegin(GL_QUADS);
    glNormal3f( 0.0f, 1.0f, 0.0f);
    glTexCoord2f(0,0);
    glVertex3f(vertices[0],vertices[1],vertices[2]);
    glTexCoord2f(1,0);
    glVertex3f(vertices[3],vertices[4],vertices[5]);
    glTexCoord2f(1,1);
    glVertex3f(vertices[6],vertices[7],vertices[8]);
    glTexCoord2f(0,1);
    glVertex3f(vertices[9],vertices[10],vertices[11]);
    glEnd();

    /* Drawing plane automatically
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);

    glDisableClientState(GL_VERTEX_ARRAY); */

    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
}
