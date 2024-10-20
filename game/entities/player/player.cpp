#include "player.hpp"
#include <iostream>

using namespace std;

Player::Player(int newId): Entity(newId)
{
    id = newId;
}

void Player::handleKeyPress(std::vector<int> *keysPressed)
{
    cout << "player recebeu " << keysPressed->size() << " teclas apertadas";
}
