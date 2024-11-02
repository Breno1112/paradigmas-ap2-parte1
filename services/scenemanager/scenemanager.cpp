#include "scenemanager.hpp"
#include <iostream>

#ifndef LEVEL_DECLARATOR_SCENE_H
#define LEVEL_DECLARATOR_SCENE_H
#include "../../game/scenes/leveldeclaratorscene/leveldeclaratorscene.hpp"
#endif

using namespace std;

std::shared_ptr<Scene> SceneManager::getScene(int id)
{
    if(id == 0) {
        MainMenuScene s = MainMenuScene();
        s.finished = false;
        runningScene = make_shared<MainMenuScene>(s);
    } else {
        LevelDeclaratorScene s = LevelDeclaratorScene(id);
        s.finished = false;
        runningScene = make_shared<LevelDeclaratorScene>(s);
    }
    return runningScene;
}