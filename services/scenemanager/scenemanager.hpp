#ifndef SCENE_H
#include "../../game/scenes/scene.hpp"
#define SCENE_H
#endif

#include <memory>

#include "../../game/scenes/mainmenuscene/mainmenuscene.hpp"

class SceneManager {

    std::shared_ptr<Scene> runningScene;

    public:
        SceneManager() {};

    std::shared_ptr<Scene> getScene(int id);
};