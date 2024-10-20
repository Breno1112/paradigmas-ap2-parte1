#include "../services/scenemanager/scenemanager.hpp"

class Game {

    
    private:
        SceneManager sceneManager;
        std::shared_ptr<Scene> scene;
        int MAX_FPS = 5;
        int MAX_WIDTH = 50;
        int MAX_HEIGHT = 20;

        bool gameRunning = false;

        void startInternalGameThread();

        void loadScene(std::shared_ptr<Scene> newScene);


    public:
        void update();

        void paint();

        void start();

        void stop();

        Game();
};