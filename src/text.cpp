#include "text.h"

text::text()
{
    //ctor
}

text::~text()
{
    //dtor
}

void text::renderText(std::string str, float px, float py, float r, float g, float b, float alpha)
{
    int l = str.size(), i;
    //std::cout<<str<<std::endl;
    glPushMatrix();
        glColor4f(r, g, b ,alpha);
        glRasterPos3f(px, py, 0);
        for(i = 0; i < l; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
        }
    glPopMatrix();
}
