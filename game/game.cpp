#include <iostream>
#include "game.hpp"
#include <chrono>
using namespace std;

void Game::startInternalGameThread()
{
    std::chrono::milliseconds lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );

    while(gameRunning) {
        std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        );
        auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTime).count();
        if(delta >= (1000 / MAX_FPS)) {
            update();
            paint();
            lastTime = now;
        }
    }
}


void Game::update()
{
    scene.update();
}

void Game::paint()
{
    scene.paint();
}

void Game::start()
{
    cout << "iniciando jogo" << endl;
    gameRunning = true;
    startInternalGameThread();
}

void Game::stop()
{
    gameRunning = false;
    cout << "Finalizando jogo" << endl;
}

Game::Game()
{
    scene = Scene();
}

void Game::loadScene(Scene newScene)
{
    scene = newScene;
}
