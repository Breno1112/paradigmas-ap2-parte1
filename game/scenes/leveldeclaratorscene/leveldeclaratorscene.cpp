#include "leveldeclaratorscene.hpp"

using namespace std;

std::string LevelDeclaratorScene::updateScreenPlaceholders(std::string line)
{
    int pos = line.find("$");
    if(pos != std::string::npos) {
        line.replace(pos, 1, std::to_string(nextLevel));
    }
    return line;
}

LevelDeclaratorScene::LevelDeclaratorScene(int nextLevelToPoint)
{
    sceneId = 1;
    nextLevel = nextLevelToPoint;
    startTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );
    lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );
}

void LevelDeclaratorScene::update()
{
    lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );

    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(lastTime - startTime).count();
    if(delta >= waitTimeMs) {
        finish(nextLevel);
    }
}

void LevelDeclaratorScene::paint()
{
    int count = 0;

    while(count < screenBuffer.size()) {
        std::string line = screenBuffer[count];
        line = updateScreenPlaceholders(line);
        cout << line << endl;
        count = count + 1;
    }
}
