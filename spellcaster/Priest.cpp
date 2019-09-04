#include "Priest.hpp"

Priest::Priest(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana) {
        this->magicAbility = new PriestAbility(this, heal);
}
Priest::~Priest() {};
