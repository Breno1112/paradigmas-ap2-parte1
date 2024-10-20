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
        if(keysPressed->at(count) == K_W_KEY || keysPressed->at(count) == K_UP_ARROW_KEY) {
            willGoUp = true;
        } else if(keysPressed->at(count) == K_S_KEY || keysPressed->at(count) == K_DOWN_ARROW_KEY) {
            willGoDown = true;
        } else if(keysPressed->at(count) == K_A_KEY || keysPressed->at(count) == K_LEFT_ARROW_KEY) {
            willGoLeft = true;
        } else if(keysPressed->at(count) == K_D_KEY || keysPressed->at(count) == K_RIGHT_ARROW_KEY) {
            willGoRight = true;
        } else if(keysPressed->at(count) == K_SPACE_KEY) {
            willFire = true;
        }
        count = count + 1;
    }
    if(willGoUp && willGoDown) {
        willGoUp = false;
        willGoDown = false;
    }

    if(willGoRight && willGoLeft) {
        willGoLeft = false;
        willGoRight = false;
    }

    if(willGoUp) {
        setVelY(-1);
    } else if(willGoDown) {
        setVelY(1);
    } else if(willGoLeft) {
        setVelX(-1);
    } else if(willGoRight) {
        setVelX(1);
    }
}

void Player::update()
{
}

void Player::paint()
{
}
