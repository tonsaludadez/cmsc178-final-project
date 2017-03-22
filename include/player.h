#ifndef PLAYER_H
#define PLAYER_H

#include <windows.h>
#include <GL/glut.h>

#include "shapes.h"

class player
{
    public:
        player();
        ~player();

        void render();
        void renderPlayer();
        void ship();
        void banana();
        void cockpit();
        float getFuel();
        void setFuel(float);

        float getPlayerPosX();
        float getPlayerPosY();
        void setPlayerPos(float, float);
        void setPlayerPosX(float);
        void setPlayerPosY(float);

        float getShipHeight();

    protected:

    private:
        float fuel;
        float posX;
        float posY;

        static const float bananaHeight = 0.09;
        static const float bananaWidth = 0.04;
        static const float shipHeight = 0.04;
        static const float shipWidth = 0.15;
        static const float cockpitHeight = 0.1;
        static const float cockpitWidth = 0.09;
};

#endif // PLAYER_H
