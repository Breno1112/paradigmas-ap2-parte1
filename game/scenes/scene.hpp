#include <functional>

#include "../../services/keyboardservice/keyboardservice.hpp"

#include <string>

#ifndef ENTIY_H
#define ENTIY_H
#include "../entities/entity.hpp"
#endif

class Scene {

    private:
        void finish(int nextScene);

    public:

        KeyboardService keyboardService;

        std::vector<std::string> screenBuffer = {};

        std::vector<Entity> entities = {};

        int nextScene = 0;

        bool finished = false;

        virtual void onKeyPress();

        virtual void paint();

        virtual void update();

        Scene() {};
};