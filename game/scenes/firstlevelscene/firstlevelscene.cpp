#include "firstlevelscene.hpp"
#include <iostream>


using namespace std;
FirstLevelScene::FirstLevelScene()
{
    player = make_optional<Player>(Player(1));
    player.value().setY(17);

    finishZoneStartX = 45;
    finishZoneEndX = 50;
    finishZoneStartY = 0;
    finishZoneEndY = 3;
}

void FirstLevelScene::update()
{
    checkPlayerWon();
    onKeyPress();
    if(player.has_value()) {
        player.value().update(screenBuffer);
    }
}

void FirstLevelScene::paint()
{
    int count = 0;

    if(player.has_value()) {
        player.value().paint(screenBuffer);
    }

    while(count < screenBuffer.size()) {
        std::string line = screenBuffer[count];
        cout << line << endl;
        count = count + 1;
    }
}

void FirstLevelScene::onKeyPress()
{
    std::vector<int> keysPressed = keyboardService.getKeysPressed({
        K_W_KEY,  
        K_UP_ARROW_KEY,
        K_LEFT_ARROW_KEY,
        K_A_KEY,
        K_RIGHT_ARROW_KEY,
        K_D_KEY
    });

    if(player.has_value()) {
        player.value().handleKeyPress(&keysPressed);
    }
}

void FirstLevelScene::checkPlayerWon()
{
    Player p = player.value();
    if(p.x >= finishZoneStartX && p.x <= finishZoneEndX && p.y >= finishZoneStartY && p.y <= finishZoneEndY) {
        finish(2);
    }
}