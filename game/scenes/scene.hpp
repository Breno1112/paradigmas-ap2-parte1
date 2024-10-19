#include <functional>

class Scene {

    private:
        void finish(int nextScene);

    public:

        int nextScene = 0;

        bool finished = false;

        void onKeyPress();

        void paint();

        void update();

        Scene() {};
};