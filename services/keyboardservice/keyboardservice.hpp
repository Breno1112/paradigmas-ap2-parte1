#include <vector>
#include <windows.h>

class KeyboardService {

    public:
        KeyboardService() {}

        std::vector<int> getKeysPressed(std::vector<int> keysToCheck);
};