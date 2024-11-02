#include "scenemanager.hpp"
#include <iostream>

#ifndef LEVEL_DECLARATOR_SCENE_H
#define LEVEL_DECLARATOR_SCENE_H
#include "../../game/scenes/leveldeclaratorscene/leveldeclaratorscene.hpp"
#endif

#ifndef FIRST_LEVEL_SCENE_H
#define FIRST_LEVEL_SCENE_H
#include "../../game/scenes/firstlevelscene/firstlevelscene.hpp"
#endif

using namespace std;

std::shared_ptr<Scene> SceneManager::getScene(int nextSceneId, int callerSceneId)
{
    if(nextSceneId == 0) {
        MainMenuScene s = MainMenuScene();
        s.finished = false;
        runningScene = make_shared<MainMenuScene>(s);
    } else if(callerSceneId == 1) {
        if(nextSceneId == 2) {
            FirstLevelScene s = FirstLevelScene();
            s.finished = false;
            runningScene = make_shared<FirstLevelScene>(s);
        } else {
            runningScene = make_shared<Scene>(Scene());
        }
    } else {
        LevelDeclaratorScene s = LevelDeclaratorScene(nextSceneId);
        s.finished = false;
        runningScene = make_shared<LevelDeclaratorScene>(s);
    }
    return runningScene;
}