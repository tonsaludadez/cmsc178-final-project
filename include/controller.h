#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>

#include "background.h"
#include "collision.h"
#include "gameClock.h"
#include "logic.h"
#include "obstacle.h"
#include "platform.h"
#include "player.h"
#include "shapes.h"

class controller
{
    public:
        controller();
        ~controller();

        //void bg();
        void changeBG();
        void gameStart();
        void initLevel();
        void newGame();

        collision CollisionHandler;
        gameClock GameClock;
        logic Logic;
        obstacle Obstacle;
        platform Platform;
        player Player;

        bool isGame;
        bool keys[256];
        bool gameOver;
        bool tutorialMode;

        int level;
        int life;

        int score;
    protected:

    private:
        static const float gravity = -9.8;
};

#endif // CONTROLLER_H
