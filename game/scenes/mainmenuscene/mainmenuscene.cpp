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

    count = 0;

    while(count < screenBuffer.size()) {
        cout << screenBuffer[count] << endl;
        count = count + 1;
    }
}

void MainMenuScene::onKeyPress()
{
    std::vector<int> keysPressed = keyboardService.getKeysPressed({
        K_W_KEY, 
        K_A_KEY,
        K_S_KEY, 
        K_D_KEY, 
        K_UP_ARROW_KEY, 
        K_DOWN_ARROW_KEY, 
        K_LEFT_ARROW_KEY, 
        K_RIGHT_ARROW_KEY, 
        K_SPACE_KEY,
        });
    // cout << "Apertando " << keysPressed.size() << " teclas neste momento" << endl;

    if(player.has_value()) {
        player.value().handleKeyPress(&keysPressed);
    }
}
