#include "gamewinscene.hpp"

using namespace std;

void GameWinScene::update()
{
    lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );

    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(lastTime - startTime).count();
    if(delta >= waitTimeMs) {
        finish(-1);
    }
}

void GameWinScene::paint()
{
    int count = 0;

    while(count < screenBuffer.size()) {
        std::string line = screenBuffer[count];
        cout << line << endl;
        count = count + 1;
    }
}

GameWinScene::GameWinScene()
{
    sceneId = 2;
    startTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );
    lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );
}