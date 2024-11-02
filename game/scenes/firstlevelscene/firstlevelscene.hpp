#ifndef SCENE_H
#define SCENE_H
#include "../scene.hpp"
#endif

class FirstLevelScene: public Scene {


    private:
        std::vector<std::string> screenBuffer = {
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
            "..................................................",
            "..................................................",
            "..................................................",
            "..................................................",
            ".....||..............+..+.........................",
            ".....||.............======........................",
            "=================================================="
        };

    public:
        FirstLevelScene();

        void update() override;

        void paint() override;

};