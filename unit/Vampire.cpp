#include "Vampire.hpp"

Vampire::Vampire(const char* title, int hitPoints, int damage)
    : Unit(title, hitPoints, damage) {
        this->ability = new VampireAbility(this);
        this->undead = true;
}
Vampire::~Vampire() {};