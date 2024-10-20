#ifndef SCENE_H
#define SCENE_H
#include "../scene.hpp"
#endif

class MainMenuScene: public Scene {

    private:
        char screenBuffer[20][50] = {};

    public:
        MainMenuScene();

        void update() override;

        void paint() override;

        void onKeyPress() override;
        
};