#ifndef SHAPES_H
#define SHAPES_H

#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159
#define DEG2RAD PI/180.0


class shapes
{
    public:
        shapes();
        ~shapes();

        static void drawColoredCircle(float, float, int, float, float);
        static void drawEllipse(float, float, int, float, float);
        static void drawPolygon1(float, float, float, float);
        static void drawPolygon2(float, float, float, float);

    protected:

    private:
};

#endif // SHAPES_H
