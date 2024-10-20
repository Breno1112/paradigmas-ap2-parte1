#ifndef ENTIY_H

#define ENTIY_H

#include "../entity.hpp"

#endif

class Player: public Entity {

    public:
        Player(int newId);

        void handleKeyPress(std::vector<int>* keysPressed) override;
};