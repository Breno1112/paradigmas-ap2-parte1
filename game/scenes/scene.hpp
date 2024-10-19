#include <functional>

class Scene {

    private:
        void finish(int nextScene);

    public:

        int nextScene = 0;

        bool finished = false;

        virtual void onKeyPress();

        virtual void paint();

        virtual void update();

        Scene() {};
};