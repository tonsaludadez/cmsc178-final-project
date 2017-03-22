#include "player.h"

player::player()
{
    fuel = 100;
}

player::~player()
{
    //dtor
}

void player::render()
{

}

void player::renderPlayer()
{
    ship();
    cockpit();
    banana();

}

void player::ship()
{
    //glColor4f(1, 1, 1, 1 * 0.5);
    glColor3f(0.556863, 0.137255, 0.419608);
    shapes::drawEllipse(getPlayerPosX(), getPlayerPosY(), 360, shipWidth, shipHeight);
    shapes::drawColoredCircle(getPlayerPosX(), getPlayerPosY(), 361, shipWidth, shipHeight);

}

void player::banana()
{
    glColor3f(1, 1, 0);
    shapes::drawEllipse(getPlayerPosX() - 0.02, getPlayerPosY() + 0.01, 90, bananaWidth, bananaHeight);
    shapes::drawColoredCircle(getPlayerPosX() - 0.02, getPlayerPosY() + 0.01, 91, bananaWidth, bananaHeight);

    glColor3f(0, 0, 0);
    shapes::drawColoredCircle(getPlayerPosX() -0.016, getPlayerPosY() + 0.05 + 0.01, 360, 0.005, 0.005);
    shapes::drawColoredCircle(getPlayerPosX() +0.011, getPlayerPosY() + 0.05 + 0.01, 360, 0.005, 0.005);
}

void player::cockpit()
{
    glColor3f(1, 1, 1);
    shapes::drawEllipse(getPlayerPosX(), getPlayerPosY() + 0.01, 180, cockpitWidth, cockpitHeight);
    glColor4f(0,0,0, 0.4);
    shapes::drawColoredCircle(getPlayerPosX(), getPlayerPosY() + 0.01, 181, cockpitWidth, cockpitHeight);
}

float player::getFuel()
{
    return fuel;
}

void player::setFuel(float fuel)
{
    this->fuel = fuel;
}

float player::getPlayerPosX()
{
    return posX;
}

float player::getPlayerPosY()
{
    return posY;
}

void player::setPlayerPos(float x, float y)
{
    setPlayerPosX(x);
    setPlayerPosY(y);
}

void player::setPlayerPosX(float posX)
{
    this->posX = posX;
}

void player::setPlayerPosY(float posY)
{
    this->posY = posY;
}

float player::getShipHeight()
{
    return shipHeight;
}
