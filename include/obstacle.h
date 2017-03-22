#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <windows.h>
#include <GL/glut.h>

#include "shapes.h"

class obstacle
{
    public:
        obstacle();
        ~obstacle();

        void renderObstacle();
        float getObstaclePosX();
        float getObstaclePosY();

        void setObstacleDimensions(float, float);
        void setObstaclePos(float, float);
        void setObstaclePosX(float);
        void setObstaclePosY(float);

        float getObstacleHeight();
        float getObstacleWidth();
    protected:

    private:
        float posX;
        float posY;
        float height;
        float width;
};

#endif // OBSTACLE_H
