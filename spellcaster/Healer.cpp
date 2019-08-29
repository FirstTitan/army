#include "Healer.hpp"

Healer::Healer(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana) {
        this->magicAbility = new HealerAbility(this, new Heal(30, 30));

}

Healer::~Healer() {};