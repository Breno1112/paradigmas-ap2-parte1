#ifndef ENTIY_H
#define ENTIY_H
#include "../entity.hpp"
#endif

#ifndef KEYBOARD_CONTANTS_H
#define KEYBOARD_CONTANTS_H
#include "../../../helpers/keyboardconstants.hpp"
#endif

class Player: public Entity {

    public:
        Player(int newId);

        // este método não deve atualizar as variáveis de posição 
        // ou aceleração do player. Só deve mudar a direção. 
        // As atualizações de posição e direção deverão ser feitas no método update()
        void handleKeyPress(std::vector<int>* keysPressed) override;

        void update() override;

        void paint(std::vector<std::string> &screen) override;
};