#include "scenemanager.hpp"
#include <iostream>

using namespace std;

Scene SceneManager::getScene(int id)
{
    if(id == 0) {
        return Scene();
    } else {
        cout << "retornando cena main menu";
        return MainMenuScene();
    }
}