#include "Wizard.hpp"

Wizard::Wizard(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana) {
        this->magicAbility = new MagicAbility(this, new FireBall(30, 30));
}

Wizard::~Wizard() {};