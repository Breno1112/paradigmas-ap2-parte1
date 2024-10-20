#include "mainmenuscene.hpp"
#include <iostream>

using namespace std;

MainMenuScene::MainMenuScene()
{
    player = make_optional<Player>(Player(1));
}

void MainMenuScene::update()
{
    onKeyPress();
    if(player.has_value()) {
        player.value().update();
    }
    int count = 0;
    while(count < enemies.size()) {
        enemies[count]->update();
        count = count + 1;
    }
}

void MainMenuScene::paint()
{
    if(player.has_value()) {
        player.value().paint();
    }
    int count = 0;
    while(count < enemies.size()) {
        enemies[count]->paint();
        count = count + 1;
    }
}

void MainMenuScene::onKeyPress()
{
    std::vector<int> keysPressed = keyboardService.getKeysPressed({
        keyboardService.W_KEY, 
        keyboardService.A_KEY,
        keyboardService.S_KEY, 
        keyboardService.D_KEY, 
        keyboardService.UP_ARROW_KEY, 
        keyboardService.DOWN_ARROW_KEY, 
        keyboardService.LEFT_ARROW_KEY, 
        keyboardService.RIGHT_ARROW_KEY, 
        keyboardService.SPACE_KEY,
        });
    // cout << "Apertando " << keysPressed.size() << " teclas neste momento" << endl;

    if(player.has_value()) {
        player.value().handleKeyPress(&keysPressed);
    }
}
