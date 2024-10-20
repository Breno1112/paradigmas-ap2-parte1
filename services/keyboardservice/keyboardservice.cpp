#include "keyboardservice.hpp"
#include <vector>

std::vector<int> KeyboardService::getKeysPressed(std::vector<int> keysToCheck)
{

    std::vector<int> keysPressed = {};

    int count = 0;
    while(count < keysToCheck.size()) {
        if(GetAsyncKeyState(keysToCheck[count]) & 0x8000) {
            keysPressed.insert(keysPressed.begin() + keysPressed.size(), keysToCheck[count]);
        }
        count = count + 1;
    }

    return keysPressed;
}
