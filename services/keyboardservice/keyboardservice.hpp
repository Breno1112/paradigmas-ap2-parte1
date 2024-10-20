#include <vector>
#include <windows.h>

#ifndef KEYBOARD_CONTANTS_H
#define KEYBOARD_CONTANTS_H
#include "../../helpers/keyboardconstants.hpp"
#endif

class KeyboardService {

    public:
        KeyboardService() {}

        // DE ACORDO COM https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
        // DECLARANDO NA CLASSE POIS QUAL API A CLASSE USA NÃO DEVERIA TER IMPORTÂNCIA PRA QUEM CHAMA SEUS MÉTODOS

        std::vector<int> getKeysPressed(std::vector<int> keysToCheck);
};