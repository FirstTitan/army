#include "Vampire.hpp"

Vampire::Vampire(const char* title, int hitPoints, int damage)
    : Unit(title, hitPoints, damage) {
        this->ability = new VampireAbility(this);
        this->undead = true;
        this->vampire = true;
}
Vampire::~Vampire() {};

void Vampire::turnToVampire(Unit* unit) {
    if ( !unit->isWerewolf() ) {
        delete(unit);
        unit = new Vampire("Vampire", 200, 30);
        this->setVampire(unit, true);
        this->setUndead(unit, true);
    }
}