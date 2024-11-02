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
    if(x < 0) {
        x = 0;
    } else if(x > 48) {
        x = 48;
    }
    if(y < 0) {
        y = 0;
    } else if(y > 18) {
        y = 18;
    }

    // cout << "Player coordinates are: X = " << x << ";  Y = " << y << endl;
}

// Apenas atualizar o screen buffer. Quem fará o print são as cenas
void Player::paint(std::vector<std::string> &screen)
{
    // cout << "player paint";
    // screen[0] = "oi";
    int count = 0;
    while(count < screen.size()) {
        std::string line = screen[count];
        int pos = line.find("[]");
        if(pos != std::string::npos) {
            screen[count] = line.replace(pos, 2, "..");
        }
        count = count + 1;
    }
    std::string firstLine = screen[y];
    std::string secondLine = screen[y + 1];
    firstLine.replace(firstLine.begin() + x, firstLine.begin() + x + 2, "[]");
    secondLine.replace(secondLine.begin() + x, secondLine.begin() + x + 2, "[]");
    screen[y] = firstLine;
    screen[y + 1] = secondLine;
    
}
