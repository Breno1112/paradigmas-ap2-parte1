#include "leveldeclaratorscene.hpp"
#include <iostream>

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
    nextLevel = nextLevelToPoint;
}

void LevelDeclaratorScene::update()
{
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
