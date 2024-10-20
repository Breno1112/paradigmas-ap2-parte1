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
    cout << "player recebeu " << keysPressed->size() << " teclas apertadas" << endl;
}

void Player::update()
{
    cout << "Player update" << endl;
}

void Player::paint()
{
    cout << "Player paint" << endl;
}
