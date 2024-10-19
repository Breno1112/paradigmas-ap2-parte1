#include "scenemanager.hpp"
#include <iostream>

using namespace std;

Scene* SceneManager::getScene(int id)
{
    Scene s;
    Scene* pointer;
    if(id == 0) {
        s = Scene();
    } else {
        cout << "retornando main scene";
        s = MainMenuScene();
    }
    pointer = &s;
    return pointer;
}