#ifndef WIZARD_HPP
#define WIZARD_HPP

#include "SpellCaster.hpp"
#include "../spell/FireBall.hpp"

class Wizard : public SpellCaster {
    public:
        Wizard(const char* title, int hitPoints, int damage, int mana);
        virtual ~Wizard();
};

#endif //WIZARD_HPP