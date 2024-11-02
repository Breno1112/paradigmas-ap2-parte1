#include "firstlevelscene.hpp"
#include <iostream>


using namespace std;
FirstLevelScene::FirstLevelScene()
{
}

void FirstLevelScene::update()
{
}

void FirstLevelScene::paint()
{
    int count = 0;

    while(count < screenBuffer.size()) {
        std::string line = screenBuffer[count];
        cout << line << endl;
        count = count + 1;
    }
}
