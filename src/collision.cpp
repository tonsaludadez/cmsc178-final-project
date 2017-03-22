#include "collision.h"

collision::collision()
{
    //ctor
}

collision::~collision()
{
    //dtor
}

bool collision::checkCollision(float playerX, float playerY, float platformX, float platformY)
{
    int i;
    for(i = 0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        float width = (cos(rad) * SHIP_WIDTH) + playerX;
        float height = (sin(rad) * SHIP_HEIGHT) + playerY;

        if(width > platformX - PLATFORM_WIDTH/2 &&
           width < platformX + PLATFORM_WIDTH/2 &&
           height > platformY - PLATFORM_HEIGHT/2 &&
           height < platformY + PLATFORM_HEIGHT/2 &&
           playerY > platformY)
        {
            return true;
        }

    }

    return false;
}

bool collision::checkCollisionObj(float playerX, float playerY, float objX, float objY, float obj_height, float obj_width)
{
    int i;
    for(i = 0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        float width = (cos(rad) * SHIP_WIDTH) + playerX;
        float height = (sin(rad) * SHIP_HEIGHT) + playerY;

        if(width > objX - obj_width/2 &&
           width < objX + obj_width/2 &&
           height > objY - obj_height/2 &&
           height < objY + obj_height/2 &&
           playerY > objY)
        {
            return true;
        }

        if(width > objX - obj_width/2 &&
           width < objX + obj_width/2 &&
           height +0.1 > objY - obj_height/2 &&
           height +0.1 < objY + obj_height/2 &&
           playerY < objY)
        {
            return true;
        }

    }

    return false;
}
