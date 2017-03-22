#ifndef PLATFORM_H
#define PLATFORM_H

#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <time.h>

#include "shapes.h"

class platform
{
    public:
        platform();
        ~platform();

        void randomizePlatformPos();
        void renderPlatform();
        void renderPlatformLines();

        float getPlatformPosX();
        float getPlatformPosY();
        void setPlatformPos(float, float);
        void setPlatformPosX(float);
        void setPlatformPosY(float);

        float getPlatformHeight();
    protected:

    private:
        float posX;
        float posY;
        static const float height = 0.02;
        static const float width = 0.4;
};

#endif // PLATFORM_H
