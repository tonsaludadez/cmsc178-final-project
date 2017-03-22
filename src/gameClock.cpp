#include "gameClock.h"

gameClock::gameClock()
{
    begTime = clock();
}

gameClock::~gameClock()
{
    //dtor
}

unsigned long gameClock::elapsedTime()
{
    return ((unsigned long) clock() - begTime); // CLOCKS_PER_SEC;
}
