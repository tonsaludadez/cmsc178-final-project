#include "logic.h"

logic::logic()
{
    //ctor
    left_pressed = false;
    right_pressed = false;
    up_pressed = false;
    //failLevel = false;
    //completeLevel = false;
}

logic::~logic()
{
    //dtor
}

void logic::checkAction()
{
    //Left
    if(keys[100])
    {
        //Player->setPlayerPosX(Player->getPlayerPosX() - 0.05);
        //go left
        if(!left_pressed)
        {
            if(left_elapsed.elapsedTime() > 500)
            {
                keys[100] = false;
            }
        }
        else
        {
            Player->setFuel(Player->getFuel() - 1.5);
        }


        Player->setPlayerPosX(Player->getPlayerPosX() - 0.03);
        keys[102] = false;
    }

    if(keys[101])
    {
        if(!up_pressed)
        {
            if(up_elapsed.elapsedTime() > 200)
            {
                keys[101] = false;
            }
        }
        else
        {
            Player->setFuel(Player->getFuel() - 1.5);
        }

        Player->setPlayerPosY(Player->getPlayerPosY() + 0.03);
    }

    if(keys[102])
    {
        if(!right_pressed)
        {
            if(right_elapsed.elapsedTime() > 500)
            {
                keys[102] = false;
            }
        }
        else
        {
            Player->setFuel(Player->getFuel() - 1.5);
        }


        Player->setPlayerPosX(Player->getPlayerPosX() + 0.03);
        keys[100] = false;
    }

    if(!keys[101])
    {
        Player->setPlayerPosY(Player->getPlayerPosY() - (0.07 * (GRAVITY * (falling_elapsed.elapsedTime()/(CLOCKS_PER_SEC / 4))  )));
        //std::cout<<GRAVITY * (falling_elapsed.elapsedTime()/CLOCKS_PER_SEC)<<std::endl;
    }

    //std::cout<<falling_elapsed.elapsedTime()/CLOCKS_PER_SEC<<std::endl;
    if(left_pressed || right_pressed || up_pressed)
    {
        sound::playRocket();
    }

    left_pressed = false;
    right_pressed = false;
    up_pressed = false;
}

void logic::runLogic()
{
    if(Player->getFuel() > 0)
    {
        checkAction();

        if(collision::checkCollision(Player->getPlayerPosX(), Player->getPlayerPosY(),
                                     Platform->getPlatformPosX(), Platform->getPlatformPosY()))
        {
            if(Player->getPlayerPosY() - Player->getShipHeight()/2 > Platform->getPlatformPosY() + Platform->getPlatformHeight()/2){
                if(falling_elapsed.elapsedTime() < 2000)
                {
                    //std::cout<<"GOOD!";
                    completeLevel = true;
                }

                else
                {
                    //std::cout<<"BAD!";
                    failLevel = true;

                    sound::playDeath();
                }
            }


            else
            {
                //std::cout<<"BAD!";
                failLevel = true;
                sound::playDeath();
            }

        }

        if(collision::checkCollisionObj(Player->getPlayerPosX(), Player->getPlayerPosY(),
                                         Obstacle->getObstaclePosX(), Obstacle->getObstaclePosY(),
                                        Obstacle->getObstacleHeight(), Obstacle->getObstacleWidth()))
        {
            failLevel = true;

            sound::playDeath();
        }

        if(Player->getPlayerPosX() > 2 || Player->getPlayerPosX() < -2){
            failLevel = true;
        }
        if(Player->getPlayerPosY() > 2 || Player->getPlayerPosY() < -2){
            failLevel = true;
        }
    }

}
