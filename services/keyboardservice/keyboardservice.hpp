#include <vector>
#include <windows.h>

class KeyboardService {

    public:
        KeyboardService() {}

        // DE ACORDO COM https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
        // DECLARANDO NA CLASSE POIS QUAL API A CLASSE USA NÃO DEVERIA TER IMPORTÂNCIA PRA QUEM CHAMA SEUS MÉTODOS
        static const int W_KEY = 0x57;
        static const int A_KEY = 0x41;
        static const int S_KEY = 0x53;
        static const int D_KEY = 0x44;
        static const int UP_ARROW_KEY = 0x26;
        static const int DOWN_ARROW_KEY = 0x28;
        static const int LEFT_ARROW_KEY = 0x25;
        static const int RIGHT_ARROW_KEY = 0x27;
        static const int SPACE_KEY = 0x20;

        std::vector<int> getKeysPressed(std::vector<int> keysToCheck);
};