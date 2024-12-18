#include <functional>

#include "../../services/keyboardservice/keyboardservice.hpp"
#include <optional>

#ifndef ENTIY_H
#define ENTIY_H
#include "../entities/entity.hpp"
#endif

#ifndef PLAYER_H
#define PLAYER_H
#include "../entities/player/player.hpp"
#endif


class Scene {

    public:

        int finishZoneStartX = 1000;

        int finishZoneEndX = 1000;

        int finishZoneStartY = 1000;

        int finishZoneEndY = 1000;

        void finish(int nextScene);

        KeyboardService keyboardService;

        std::vector<Entity*> enemies = {};

        std::optional<Player> player = {};

        int nextScene = 0;

        int sceneId = 0;

        bool finished = false;

        virtual void onKeyPress();

        virtual void paint();

        virtual void update();

        Scene() {};
};