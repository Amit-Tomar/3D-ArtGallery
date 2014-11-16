#include "BuildingBlock.h"

GLfloat vertices[] =  { -0.5f, 0.0f, 0.5f,   0.5f, 0.0f, 0.5f,   0.5f, 0.0f, -0.5f,  -0.5f, 0.0f, -0.5f};

        GLfloat texcoords[] =       { 0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,

                             };

        GLubyte cubeIndices[24] = {0,1,2,3};

BuildingBlock::BuildingBlock(std::string path)
{
    textureImagePath = path;
    textureBinded = false;

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    textureImagePath = path;
    image = (Image *) malloc(sizeof(Image));

    if (image == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }

    if( 0 == loadImage())
    {
        std::cerr << "Texture image was not loaded properly" << std::endl ;
    }
}

void BuildingBlock::traverseNode()
{
    renderBuildingBlock();
}

void BuildingBlock::renderBuildingBlock()
{
    if( !textureBinded )
    {
        glGenTextures(1, &textureId);
        textureBinded = true;

        std::cout << "Tex id " << textureId << std::endl;
    }

    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,image->sizeX,image->sizeY,0,GL_RGB,GL_UNSIGNED_SHORT_5_6_5,image->data);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glColor4f(1,1,1,1);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
    glVertexPointer(3, GL_FLOAT, 0, vertices);


    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_TEXTURE_2D);
}

int BuildingBlock::loadImage()
{
    FILE *file;
    unsigned long size, i;
    unsigned short int planes, bpp;
    char temp;

    if ((file = fopen(textureImagePath.c_str(), "rb"))==NULL)
    {
        printf("File Not Found : %s\n",textureImagePath.c_str());
        return 0;
    }

    fseek(file, 18, SEEK_CUR);

    if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
        printf("Error reading width from %s.\n", textureImagePath.c_str());
        return 0;
    }
    if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
        printf("Error reading height from %s.\n", textureImagePath.c_str());
        return 0;
    }

    size = image->sizeX * image->sizeY * 2;

    if ((fread(&planes, 2, 1, file)) != 1) {
        printf("Error reading planes from %s.\n", textureImagePath.c_str());
        return 0;
    }
    if (planes != 1) {
        printf("Planes from %s is not 1: %u\n", textureImagePath.c_str(), planes);
        return 0;
    }
    if ((i = fread(&bpp, 2, 1, file)) != 1) {
        printf("Error reading bpp from %s.\n", textureImagePath.c_str());
        return 0;
    }
    if (bpp != 16) {
        printf("Bpp from %s is not 16: %u\n", textureImagePath.c_str(), bpp);
        return 0;
    }

    printf("\n here -- ");
    std::cout << "here" << std::endl ;
    fseek(file, 16, SEEK_CUR);
    image->data = (char *) malloc(size);

    if (image->data == NULL) {
        printf("Error allocating memory for color-corrected image data \n");
        return 0;
    }
    if ((i = fread(image->data, size, 1, file)) != 1) {
        printf("Error reading image data from %s.\n", textureImagePath.c_str());
        return 0;
    }
    for (i=0;i<size;i+=3) {
        temp = image->data[i];
        image->data[i] = image->data[i+2];
        image->data[i+2] = temp;
    }

    return 1;
}
