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

#ifndef GAME_WIN_SCENE_H
#define GAME_WIN_SCENE_H
#include "../../game/scenes/gamewinscene/gamewinscene.hpp"
#endif

using namespace std;

std::shared_ptr<Scene> SceneManager::getScene(int nextSceneId, int callerSceneId)
{
    if(nextSceneId == 0) {
        runningScene = make_shared<MainMenuScene>(MainMenuScene());
    } else if(callerSceneId == 1) {
        if(nextSceneId == 1) {
            runningScene = make_shared<FirstLevelScene>(FirstLevelScene());
        } else {
            runningScene = make_shared<Scene>(Scene());
        }
    } else if(nextSceneId == 2) {
            runningScene = make_shared<GameWinScene>(GameWinScene());
    } else {
        runningScene = make_shared<LevelDeclaratorScene>(LevelDeclaratorScene(nextSceneId));
    }
    return runningScene;
}