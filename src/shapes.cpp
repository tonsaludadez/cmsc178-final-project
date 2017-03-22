#include "shapes.h"

shapes::shapes()
{
    //ctor
}

shapes::~shapes()
{
    //dtor
}

void shapes::drawColoredCircle(float px, float py, int loop, float a1, float a2)
{
    int i;

    glPushMatrix();
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH, GL_NICEST);

        glEnable(GL_POINT_SMOOTH);
        glHint(GL_POINT_SMOOTH, GL_NICEST);

        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(px, py);

            for(i = 0; i < loop; i++)
            {
                float rad = i * DEG2RAD;
                glVertex2f((cos(rad) * a1) + px, (sin(rad) * a2) + py);
            }
        glEnd();
}

void shapes::drawEllipse(float px, float py, int loop, float a1, float a2)
{
    int i;

    glPushMatrix();
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH, GL_NICEST);

        glEnable(GL_POINT_SMOOTH);
        glHint(GL_POINT_SMOOTH, GL_NICEST);

        glBegin(GL_LINE_LOOP);

            for(i = 0; i < loop; i++)
            {
                float rad = i*DEG2RAD;
                glVertex2f((cos(rad) * a1) + px, (sin(rad) * a2) + py);
            }
        glEnd();
    glPopMatrix();
}

void shapes::drawPolygon1(float px, float py, float height, float width)
{
    glPushMatrix();
        glBegin(GL_POLYGON);
            glVertex2f(px - (width / 2), py - (height / 2));
            glVertex2f(px + (width / 2), py - (height / 2));
            glVertex2f(px + (width / 2), py + (height / 2));
            glVertex2f(px - (width / 2), py + (height / 2));
        glEnd();
    glPopMatrix();
}

void shapes::drawPolygon2(float px, float py, float height, float width)
{
    glPushMatrix();
        glBegin(GL_POLYGON);
            glVertex2f(px - (width / 2), py - (height / 2));
            glVertex2f(px + (width / 2), py - (height / 2));
            glVertex2f(px + (width), py + (height / 2));
            glVertex2f(px + (width / 2), py + (height / 2));
        glEnd();
    glPopMatrix();
}
