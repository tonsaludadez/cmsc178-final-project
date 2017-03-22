#include "platform.h"

platform::platform()
{
    //ctor
    posX = 0;
    posY = 0;
}

platform::~platform()
{
    //dtor
}



void platform::randomizePlatformPos()
{
    float rx = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float ry = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    if(rand() % 2 == 0)
    {
        rx = rx * -1;
    }

    if(rand() % 2== 0)
    {
        ry = ry * -1;
    }

    //std::cout<<rx<<" "<<ry<<std::endl;
    setPlatformPos(rx, ry);
}

void platform::renderPlatform()
{
    glColor3f(1, 1, 0);
    shapes::drawPolygon1(posX, posY, height, width);

    glColor4f(1, 1, 1, 1);
    glPushMatrix();
        glBegin(GL_LINE_LOOP);
            glVertex2f(posX-0.001 - (width / 2), posY-0.001 - (height / 2));
            glVertex2f(posX+0.001 + (width / 2), posY-0.001 - (height / 2));
            glVertex2f(posX+0.001 + (width / 2), posY+0.001 + (height / 2));
            glVertex2f(posX-0.001 - (width / 2), posY+0.001 + (height / 2));
        glEnd();
    glPopMatrix();

    renderPlatformLines();
}

void platform::renderPlatformLines()
{
    float x = posX - width/2, y = posY - height/2;
    int lineCount;

    glColor3f(0, 0, 0);
    for(lineCount = 0; lineCount < 8; lineCount++)
    {
        shapes::drawPolygon2(x, y, 0.04, 0.02);
        x += 0.05;
    }
}

float platform::getPlatformPosX()
{
    return posX;
}

float platform::getPlatformPosY()
{
    return posY;
}

void platform::setPlatformPos(float x, float y)
{
    setPlatformPosX(x);
    setPlatformPosY(y);
}

void platform::setPlatformPosX(float posX)
{
    this->posX = posX;
}

void platform::setPlatformPosY(float posY)
{
    this->posY = posY;
}

float platform::getPlatformHeight()
{
    return height;
}
