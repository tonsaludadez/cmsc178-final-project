#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>

#include "collision.h"
#include "gameClock.h"
#include "obstacle.h"
#include "platform.h"
#include "player.h"
#include "shapes.h"
#include "sound.h"
#include "text.h"
#include "gameClock.h"

#define GRAVITY 0.098

class logic
{
    public:
        logic();
        ~logic();

        void checkAction();
        void runLogic();

        obstacle *Obstacle;
        platform *Platform;
        player *Player;
        gameClock *GameClock;
        bool *keys;
        bool left_pressed;
        bool right_pressed;
        bool up_pressed;

        gameClock left_elapsed;
        gameClock right_elapsed;
        gameClock up_elapsed;
        gameClock falling_elapsed;

        bool failLevel;
        bool completeLevel;

    protected:

    private:
};

#endif // LOGIC_H
