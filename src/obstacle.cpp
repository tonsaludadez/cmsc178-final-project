#include "obstacle.h"

obstacle::obstacle()
{
    //ctor
}

obstacle::~obstacle()
{
    //dtor
}

void obstacle::renderObstacle()
{
    glColor3f(1, 0, 0);
    shapes::drawPolygon1(posX, posY, height, width);
}

float obstacle::getObstaclePosX()
{
    return posX;
}

float obstacle::getObstaclePosY()
{
    return posY;
}

void obstacle::setObstacleDimensions(float height, float width)
{
    this->height = height;
    this->width = width;
}

void obstacle::setObstaclePos(float x, float y)
{
    setObstaclePosX(x);
    setObstaclePosY(y);
}

void obstacle::setObstaclePosX(float posX)
{
    this->posX = posX;
}

void obstacle::setObstaclePosY(float posY)
{
    this->posY = posY;
}

float obstacle::getObstacleHeight()
{
    return height;
}

float obstacle::getObstacleWidth()
{
    return width;
}
