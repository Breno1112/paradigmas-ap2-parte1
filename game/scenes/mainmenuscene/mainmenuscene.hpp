#ifndef SCENE_H
#define SCENE_H
#include "../scene.hpp"
#endif

#ifndef KEYBOARD_CONTANTS_H
#define KEYBOARD_CONTANTS_H
#include "../../helpers/keyboardconstants.hpp"
#endif

#include <string>

class MainMenuScene: public Scene {

    private:

        int selectedMenuOption = 1;

        std::vector<std::string> screenBuffer = {
            "..................................................",
            "..................................................",
            "..................................................",
            "...............{0}...NOVO JOGO....................",
            "..................................................",
            "...............{1}.....SAIR.......................",
            "..................................................",
            "..................................................",
            "..................................................",
            "..................................................",
            "..................................................",
            "..................................................",
            "..................................................",
            "..................................................",
            "..................................................",
            "..................................................",
            "..................................................",
            "..................................................",
            "..................................................",
            ".................................................."
        };

        std::string updateScreenPlaceholders(std::string line);

        void changeSelectedMenuOption(std::vector<int> keysPressed);

    public:
        MainMenuScene();

        void update() override;

        void paint() override;

        void onKeyPress() override;
        
};