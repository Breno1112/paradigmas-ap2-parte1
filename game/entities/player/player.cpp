#include "player.hpp"
#include <iostream>

using namespace std;

Player::Player(int newId): Entity(newId)
{
    id = newId;
}

void Player::handleKeyPress(std::vector<int> *keysPressed)
{
    bool willGoUp = false;
    bool willGoDown = false;
    bool willGoLeft = false;
    bool willGoRight = false;
    bool willFire = false;

    int count = 0;

    while(count < keysPressed->size()) {
        
        count = count + 1;
    }
}

void Player::update()
{
}

void Player::paint()
{
}
