#include "entity.hpp"

void Entity::setX(int newX)
{
    x = newX;
}

void Entity::setY(int newY)
{
    y = newY;
}

void Entity::setVelX(int newVelX)
{
    velX = newVelX;
}

void Entity::setVelY(int newVelY)
{
    velY = newVelY;
}

int Entity::getX()
{
    return x;
}

int Entity::getY()
{
    return y;
}

int Entity::getVelX()
{
    return velX;
}

int Entity::getVelY()
{
    return velY;
}

void Entity::handleKeyPress(std::vector<int> *keysPressed)
{
    
}

void Entity::update()
{
}

void Entity::paint()
{
}

Entity::Entity(int newId)
{
    id = newId;
}
