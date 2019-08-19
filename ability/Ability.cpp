#include "Ability.hpp"

Ability::Ability(Unit *owner) : owner(owner) {};
Ability::~Ability() {};

void Ability::attack(Unit* enemy) {
    this->owner->isAlive();

    this->enemy->takeDamage(this->owner->getDamage());
    this->enemy->counterAttack(this->owner);
}

void Ability::counterAttack(Unit* enemy) {
    this->owner->isAlive();

    this->enemy->takeDamage(this->owner->getDamage()/2);
}