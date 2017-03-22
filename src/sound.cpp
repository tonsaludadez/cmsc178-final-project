#include "sound.h"

sound::sound()
{
    //ctor
}

sound::~sound()
{
    //dtor
}

void sound::playDeath()
{
    PlaySound("invaderkilled.wav", NULL,  SND_FILENAME | SND_ASYNC);
}

void sound::playExplosion()
{
     PlaySound("explosion.wav", NULL,  SND_FILENAME | SND_ASYNC);
}

void sound::playMain()
{
    PlaySound("Science_Blaster_ft.wav", NULL,  SND_FILENAME | SND_ASYNC );
}

void sound::playRocket()
{
    PlaySound("shipmove.wav", NULL,  SND_FILENAME | SND_ASYNC);
}


