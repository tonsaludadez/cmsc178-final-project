#ifndef SOUND_H
#define SOUND_H

#include <windows.h>
#include <GL/glut.h>

class sound
{
    public:
        sound();
        ~sound();

        static void playDeath();
        static void playExplosion();
        static void playMain();
        static void playRocket();

    protected:

    private:
};

#endif // SOUND_H
