#include <vector>

class KeyboardService {

    public:
        KeyboardService() {}

        std::vector<int> getKeysPressed(std::vector<int> keysToCheck);
};