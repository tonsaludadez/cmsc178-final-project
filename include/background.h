#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stdio.h>


#include "controller.h"
#include "gameClock.h"
#include "shapes.h"
#include "text.h"


class background
{
    public:
        background();
        ~background();

        static void renderBG();
        static void renderFuel(double);
        static void renderMainMenu();
        static void renderLevelComplete();
        static void renderLife(double);
        static void renderScore(int, float, float, float);

        static void randomizeBGPos();

    protected:

    private:
};

#endif // BACKGROUND_H
