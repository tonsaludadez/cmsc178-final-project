#ifndef TEXT_H
#define TEXT_H

#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

class text
{
    public:
        text();
        ~text();

        static void renderText(std::string, float, float, float, float, float, float);

    protected:

    private:
};

#endif // TEXT_H
