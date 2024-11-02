#include "mainmenuscene.hpp"
#include <iostream>

using namespace std;

std::string MainMenuScene::updateScreenPlaceholders(std::string line)
{
    int placeholderStartPosition = 0;
    int placeholderEndPosition = 0;
    placeholderStartPosition = line.find("{");
    if(placeholderStartPosition != -1) {
        placeholderEndPosition = placeholderStartPosition + 2;
        char placeholderStrValue = line[placeholderStartPosition + 1];
        int placeholderValue = placeholderStrValue - '0';
        if(placeholderValue == selectedMenuOption) {
            line = line.replace(placeholderStartPosition , 3, "-->");
        } else {
            line = line.replace(placeholderStartPosition , 3, "...");
        }
    }
    return line;
}

void MainMenuScene::changeSelectedMenuOption(std::vector<int> keysPressed)
{
    int count = 0;
    bool pressedUp = false;
    bool pressedDown = false;
    bool pressedSpace = false;
    while(count < keysPressed.size()) {
        if(keysPressed.at(count) == K_UP_ARROW_KEY || keysPressed.at(count) == K_W_KEY) {
            pressedUp = true;
        }
        if(keysPressed.at(count) == K_DOWN_ARROW_KEY || keysPressed.at(count) == K_S_KEY) {
            pressedDown = true;
        }
        if(keysPressed.at(count) == K_SPACE_KEY) {
            pressedSpace = true;
        }
        count = count + 1;
    }
    if((pressedUp && !pressedDown) || (pressedDown && !pressedUp)) {
        selectedMenuOption = 1 - selectedMenuOption;
    }
    if(pressedSpace) {
        optionConfirmed = true;
    }
}

MainMenuScene::MainMenuScene()
{
    // criar cena com player
    // player = make_optional<Player>(Player(1));
    // criar cena sem player
    player = nullopt;
}

void MainMenuScene::update()
{
    onKeyPress();
    if(optionConfirmed) {
        if(selectedMenuOption == 1) {
            finish(-1);
        } else {
            finish(2);
        }
    }
    // if(player.has_value()) {
    //     player.value().update();
    // }
    // int count = 0;
    // while(count < enemies.size()) {
    //     enemies[count]->update();
    //     count = count + 1;
    // }
}

void MainMenuScene::paint()
{
    // if(player.has_value()) {
    //     player.value().paint(screenBuffer);
    // }
    // int count = 0;
    // while(count < enemies.size()) {
    //     enemies[count]->paint(screenBuffer);
    //     count = count + 1;
    // }

    int count = 0;

    while(count < screenBuffer.size()) {
        std::string line = screenBuffer[count];
        line = updateScreenPlaceholders(line);
        cout << line << endl;
        count = count + 1;
    }
}

void MainMenuScene::onKeyPress()
{
    std::vector<int> keysPressed = keyboardService.getKeysPressed({
        K_W_KEY,  
        K_UP_ARROW_KEY, 
        K_SPACE_KEY,
        });
    // cout << "Apertando " << keysPressed.size() << " teclas neste momento" << endl;

    // if(player.has_value()) {
    //     player.value().handleKeyPress(&keysPressed);
    // }
    changeSelectedMenuOption(keysPressed);
}
