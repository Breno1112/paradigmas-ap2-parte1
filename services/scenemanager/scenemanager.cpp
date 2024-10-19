#include "scenemanager.hpp"
#include <iostream>

using namespace std;

std::shared_ptr<Scene> SceneManager::getScene(int id)
{
    if(id == 0) {
        Scene s = Scene();
        runningScene = make_shared<Scene>(s);
    } else {
        MainMenuScene s = MainMenuScene();
        s.finished = false;
        runningScene = make_shared<MainMenuScene>(s);
    }
    return runningScene;
}