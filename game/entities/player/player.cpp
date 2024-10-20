#include "player.hpp"
#include <iostream>

using namespace std;

Player::Player(int newId): Entity(newId)
{
    id = newId;
    x = 0;
    y = 0;
    velX = 0;
    velY = 0;
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
        velY = -1;
    } else if(willGoDown) {
        velY = 1;
    } else {
        velY = 0;
    }
    
    if(willGoLeft) {
        velX = -1;
    } else if(willGoRight) {
        velX = 1;
    } else {
        velX = 0;
    }
}

void Player::update()
{
    x = x + velX;
    y = y + velY;

    cout << "Player coordinates are: X = " << x << ";  Y = " << y << endl;
}

void Player::paint()
{
}
