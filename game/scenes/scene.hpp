#include <functional>

#include "../../services/keyboardservice/keyboardservice.hpp"

class Scene {

    private:
        void finish(int nextScene);

    public:

        KeyboardService keyboardService;

        int nextScene = 0;

        bool finished = false;

        virtual void onKeyPress();

        virtual void paint();

        virtual void update();

        Scene() {};
};