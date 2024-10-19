class Entity {


    private:
        int x, y, velX, velY = 0;

    public:

        int id;
        
        void setX(int newX);
        
        void setY(int newY);

        void setVelX(int newVelX);

        void setVelY(int newVelY);

        int getX();

        int getY();

        int getVelX();

        int getVelY();

        Entity(int id);
};