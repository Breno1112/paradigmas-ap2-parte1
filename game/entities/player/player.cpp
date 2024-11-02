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

void Player::update(std::vector<std::string> &screen)
{
    cout << "player X " << x << "; player Y " << y << endl;
    collidingTop(screen);
    vector<bool> collisions = checkCollisions(screen);
    if(!collisions[0] && velY < 0) {
        y = y - 1;
        velY = velY + 1;
    }
    if(!collisions[1] && velY > 0) {
        y = y + 1;
        velY = velY - 1;
    }
    if(!collisions[2] && velX < 0) {
        x = x - 1;
        velX = velX + 1;
    }
    if(!collisions[3] && velX > 0) {
        x = x + 1;
        velX  = velX - 1;
    }
    if(x < 0) {
        x = 0;
    } else if(x > screen[x].size() - 1) {
        x = screen[x].size() - 1;
    }
    if(y < 0) {
        y = 0;
    } else if(y > screen.size() - 2) {
        y = screen.size() - 2;
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

std::vector<bool> Player::checkCollisions(std::vector<std::string> &screen)
{
    // return {true, true, false, false};
    bool collidingTop = false;
    bool collidingBottom = false;
    bool collidingLeft = false;
    bool collidingRight = false;

    cout << "aqui 1" << endl;

    int count = 0;
    while(count < collisionBlocks.size()) {
        char block = collisionBlocks[count][0]; // [0] é para transformar em char
        cout << "validando colisão contra o bloco " << block << endl;
        if(!collidingTop) { // se ainda não tiver colidido com um bloco anterior
            if(y <= 0) {
                collidingTop = true;
            } else if(y > 0 && screen[y - 1][x] == block) {
                collidingTop = true;
            }
        }
        cout << "aqui2" << endl;
        if(!collidingBottom) { // se ainda não tiver colidido com um bloco anterior
            if(y >= screen.size() - 2) {
                collidingBottom = true;
            } else if(y < screen.size() - 2 && screen[y + 2][x] == block) {
                collidingBottom = true;
            }
        }
        if(!collidingLeft) { // se ainda não tiver colidido com um bloco anterior
            if(x <= 0) {
                collidingLeft = true;
            } else if(x > 0 && (screen[y][x - 1] == block || screen[y + 1][x - 1] == block)) {
                collidingLeft = true;   
            }
        }
        if(!collidingRight) { // se ainda não tiver colidido com um bloco anterior
            if(x >= screen[0].size() - 1) {
                collidingRight = true;
            }
            if(x < screen[0].size() - 1 && (screen[y][x + 2] == block || screen[y + 1][x + 2] == block)) {
                collidingRight = true;
            }
        }
        count = count + 1;
    }

    cout << "colliding top " << collidingTop << "; colliding bottom " << collidingBottom << "; colliding left " << collidingLeft << " colliding right " << collidingRight << endl;
    return {collidingTop, collidingBottom, collidingLeft, collidingRight};
}

bool Player::collidingTop(std::vector<std::string> &screen)
{
    bool colliding = false;
    if(y <= 0) {
        colliding = true;
    }
    int count = 0;
    while(!colliding && count < collisionBlocks.size()) {
        char blockAbove = screen[y - 1][x];
        if(blockAbove == collisionBlocks[count].at(0)) {
            colliding = true;
        }
        count = count + 1;
    }
    cout << "colliding top separate method: " << colliding << endl;
    return colliding;
}
