#include "scene.hpp"
#include <iostream>

using namespace std;

void Scene::finish(int newNextScene)
{
    nextScene = newNextScene;
    finished = true;
}

void Scene::onKeyPress()
{
}

void Scene::paint()
{
    cout << "teste de cena";
}

void Scene::update()
{
}
