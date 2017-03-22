#ifndef COLLISION_H
#define COLLISION_H

#include <math.h>

#include "platform.h"
#include "player.h"

#define PLATFORM_HEIGHT 0.02
#define PLATFORM_WIDTH 0.4
#define SHIP_HEIGHT 0.04
#define SHIP_WIDTH 0.15
#define PI 3.14159
#define DEG2RAD PI/180.0

class collision
{
    public:
        collision();
        ~collision();

        static bool checkCollision(float, float, float, float);
        static bool checkCollisionObj(float, float, float, float, float, float);

    protected:

    private:
};

#endif // COLLISION_H
