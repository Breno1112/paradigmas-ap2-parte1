#ifndef SCENE_H
#include "../../game/scenes/scene.hpp"
#define SCENE_H
#endif

#include "../../game/scenes/mainmenuscene/mainmenuscene.hpp"

class SceneManager {

    public:
        SceneManager() {};

    Scene getScene(int id);
};