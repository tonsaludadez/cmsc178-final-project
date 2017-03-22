#include "background.h"

background::background()
{
    //ctor
}

background::~background()
{
    //dtor
}

void background::renderBG()
{
    randomizeBGPos();
}

void background::renderFuel(double fuel)
{
    glColor3f(1, 1, 1);
    shapes::drawPolygon1(1.3, 0.8 , 0.1, 0.38);

    float i, x = (1.3 - 0.38/2) + 0.018, y = 0.8 - 0.1;

    glColor3f(1,0,0);
    for(i = 0; i < fuel; i++)
    {
        if((int)i%2==0){
            shapes::drawPolygon1(x, 0.8, 0.09, 0.009);

            x += 0.007;
        }
    }

    text::renderText("Fuel", 1.25,0.88, 1,1,1,1);

}

void background::renderMainMenu()
{
    text::renderText("MISSION BANANA", 1, 0.1, 1,1,1,1);

    glColor4f(1,0,1,0.5);
    shapes::drawPolygon1(1.25,-0.1,0.09,0.5);

    glColor4f(1,0,1,0.5);
    shapes::drawPolygon1(1.25,-0.2,0.09,0.5);

    glColor4f(1,0,1,0.5);
    shapes::drawPolygon1(1.25,-0.3,0.09,0.5);

    text::renderText("Start", 1, -0.1, 1,1,1,1);
    text::renderText("How to play", 1, -0.2, 1,1,1,1);
    text::renderText("Exit", 1, -0.3, 1,1,1,1);
}

void background::renderLevelComplete()
{
    glColor4f(1,1,1,0.5);
    shapes::drawPolygon1(0,0,2,2);

    text::renderText("Level Complete!", -0.2,0, 1,1,1,1);

}

void background::renderLife(double life)
{
    text::renderText("Lives", 0.6, 0.88, 1,1,1,1);

    ///please fix bati implementation
    ///need in to string
    if(life == 1)
        text::renderText("1", 0.65, 0.8, 1,1,1,1);
    else if(life == 2)
        text::renderText("2", 0.65, 0.8, 1,1,1,1);
    else
        text::renderText("3", 0.65, 0.8, 1,1,1,1);
}

void background::renderScore(int score, float x, float y, float z)
{
    //text::renderText("Score", 1.23,0.69, 1,1,1,1);

    int l,i;
    char st[50];
    snprintf(st, sizeof(st), "Score: %d", score);
    l=strlen(st);

    glPushMatrix();
        glColor3f(1,1,1);
        //glRasterPos3f( 1.2,0.69,0);
        glRasterPos3f(x, y, z);
        for(i=0; i < l; i++){
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, st[i]);

        }
    glPopMatrix();
}

void background::randomizeBGPos()
{
    int star_count = rand() % 50 + 1;

    glPushMatrix();
        glBegin(GL_POINT);
            for(;star_count > 0; star_count--)
            {
                float rx = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                float ry = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

                if(rand() % 2 == 0)
                {
                    rx = rx * -1;
                }

                if(rand() % 2== 0)
                {
                    ry = ry * -1;
                }

                if(star_count % 2 == 0)
                    glColor3f(1, 1, 1);
                else
                    glColor3f(1, 1, 0);
                shapes::drawColoredCircle(rx, ry, 361, 0.002, 0.002);

                //std::cout<<rx<<" "<<ry<<std::endl;
            }
        glEnd();
    glPopMatrix();
}
