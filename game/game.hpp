#include "../services/scenemanager/scenemanager.hpp"

class Game {

    
    private:
        SceneManager sceneManager;
        Scene* scene;
        int MAX_FPS = 30;
        int MAX_WIDTH = 50;
        int MAX_HEIGHT = 20;

        bool gameRunning = false;

        void startInternalGameThread();

        void loadScene(Scene* newScene);


    public:
        void update();

        void paint();

        void start();

        void stop();

        Game();
};