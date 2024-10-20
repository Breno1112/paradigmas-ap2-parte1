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
    
}

void Game::paint()
{
    int h = 0;
    while(h < MAX_HEIGHT) {
        int w = 0;
        while(w < MAX_WIDTH) {
            cout << ".";
            w = w + 1;
        }
        cout << endl;
        h = h + 1;
    }
    cout << "\x1B[5;47;31mTick\033[0m\t\t" << endl;
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
