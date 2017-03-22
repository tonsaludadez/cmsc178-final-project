#include "controller.h"

controller::controller()
{
    isGame = false;
    controller::life = 3;
    Logic.Platform = &this->Platform;
    Logic.Player = &this->Player;
    Logic.GameClock = &this->GameClock;
    Logic.keys = keys;
    Logic.Obstacle = &this->Obstacle;
    level = 1;
    score = 0;
    gameOver = false;
    tutorialMode = false;

    Obstacle.setObstaclePos(3,3);
    Obstacle.setObstacleDimensions(0,0);
}

controller::~controller()
{
    //dtor
}

void controller::initLevel()
{
    if(level == 1)
    {
        Player.setPlayerPos(0,0);   //lvl1
        Platform.setPlatformPos(0.5, -0.8);

        Obstacle.setObstaclePos(3,3);
        Obstacle.setObstacleDimensions(0,0);
    }

    else if(level == 2)
    {
        Player.setPlayerPos(1,0);   //lvl2
        Platform.setPlatformPos(-1, 0.6);

        Obstacle.setObstaclePos(3,3);
        Obstacle.setObstacleDimensions(0,0);
    }

    else if(level == 3)
    {
        Player.setPlayerPos(-1,0);   //lvl3
        Platform.setPlatformPos(-1, 0.6);

        Obstacle.setObstacleDimensions(0.02, 2);
        Obstacle.setObstaclePos(-0.6, 0.5);
    }

    else if(level == 0)
    {
        //tutorial
        Player.setPlayerPos(-1, 0);
        Platform.setPlatformPos(1,0);
    }

    else
    {
        gameOver = true;
    }

    Player.setFuel(100);
    isGame = true;
    Logic.failLevel = false;
    Logic.completeLevel = false;
    Logic.falling_elapsed.begTime = clock();
}

void controller::gameStart()
{
    if(isGame && !Logic.completeLevel && !gameOver && level!=0)
    {
        background::renderBG();
        background::renderLife(life);
        background::renderScore(score,1.2,0.69,0);
        background::renderFuel(Player.getFuel());
        //std::cout<<"Time: "<<GameClock.elapsedTime()<<std::endl;
        Platform.renderPlatform();
        //Platform.randomizePlatformPos();

        Player.renderPlayer();

        Obstacle.renderObstacle();

        Logic.runLogic();

        //if(Player.getFuel() > 0)
        //    Player.setFuel(Player.getFuel()-0.5);
        if(Player.getFuel() <= 0)
        {
            Logic.failLevel = true;
        }

        if(Logic.failLevel)
        {
            life--;
            initLevel();
        }

        if(life == 0)
        {
            ///Gameover
            gameOver = true;
            sound::playExplosion();
        }


    }

    else if(isGame && Logic.completeLevel && !gameOver)
    {
        background::renderLevelComplete();

        if(Player.getFuel() > 0){
            background::renderScore(score,-0.11,-0.2,0);
            background::renderFuel(Player.getFuel());

            Player.setFuel(Player.getFuel() - 1);
            score ++;
        }

        else
        {
            score += life * 50;
            level++;
            initLevel();
        }
    }

    else if(gameOver)
    {
        text::renderText("Game over!", -0.18,0,1,1,1,1);
        background::renderScore(score, -0.15,-0.1,0);
        text::renderText("Press Space to return. . .", -0.33,-0.8,1,1,1,1);
    }

    else if(tutorialMode)     ///how to play
    {
        level = 0;
        initLevel();
        background::renderBG();
        Platform.renderPlatform();
        background::renderFuel(Player.getFuel());
        Player.renderPlayer();
        text::renderText("Spaceship", -1.15,-0.1,1,1,1,1);
        text::renderText("Platform", 0.9,-0.1,1,1,1,1);
        text::renderText("Carefully land the spaceship on the platform", -0.63,-0.5,1,1,1,1);
        text::renderText("Use the arrow keys to move the spaceship", -0.63,-0.6,1,1,1,1);
        text::renderText("Each move using the arrow keys will reduce the fuel", -0.73,-0.7,1,1,1,1);
        text::renderText("Press Space to play. . .", -0.3,-0.9,1,1,1,1);
    }

    else
    {
        background::renderBG();
        background::renderMainMenu();
    }

}

void controller::newGame()
{
    initLevel();

    Obstacle.setObstaclePos(3,3);
    Obstacle.setObstacleDimensions(0,0);

    level = 1;
    score = 0;
    gameOver = false;
    tutorialMode = false;
}
