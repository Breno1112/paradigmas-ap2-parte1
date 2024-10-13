class Game {

    
    private:
        int MAX_FPS = 30;

        bool gameRunning = false;

        void startInternalGameThread();


    public:
        void update();

        void paint();

        void start();

        void stop();

        Game() {}
};