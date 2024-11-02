#include <vector>
#include <string>
class Entity {

    public:
        int x, y, velX, velY = 0;

        int id;
        
        void setX(int newX);
        
        void setY(int newY);

        void setVelX(int newVelX);

        void setVelY(int newVelY);

        int getX();

        int getY();

        int getVelX();

        int getVelY();

        virtual void handleKeyPress(std::vector<int>* keysPressed);

        virtual void update();

        virtual void paint(std::vector<std::string> &screen);

        Entity(int id);
};