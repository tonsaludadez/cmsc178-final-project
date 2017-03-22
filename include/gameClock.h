#ifndef GAMECLOCK_H
#define GAMECLOCK_H

#include <time.h>

class gameClock
{
    public:
        gameClock();
        ~gameClock();

        unsigned long elapsedTime();

        unsigned long begTime;
    protected:

    private:
};

#endif // GAMECLOCK_H
