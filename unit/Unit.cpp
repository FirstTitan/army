#include "Unit.hpp"

Unit::Unit(const char* title, int hitPoints, int damage)
    : state(new State(title, hitPoints, damage)) {
        this->undead = false;
}
    
Unit::~Unit() {
    delete(this->state);
    delete(this->ability);
}

void Unit::ensureIsAlive() {
    this->state->ensureIsAlive();
}

bool Unit::isUndead() const {
    return this->undead;
}

const char* Unit::getTitle() const {
    return this->state->getTitle();
}
int Unit::getHitPoints() const {
    return this->state->getHitPoints();
}
int Unit::getHitPointsLimit() const {
    return this->state->getHitPointsLimit();
}
int Unit::getDamage() const {
    return this->state->getDamage();
}

void Unit::addHitPoints(int hp) {
    this->state->addHitPoints(hp);
}
void Unit::takeDamage(int dmg) {
    this->state->takeDamage(dmg);

    if ( this->state->getHitPoints() == 0 ) {
        this->notify();
    }
}
void Unit::takeMagicDamage(int dmg) {
    this->state->takeMagicDamage(dmg);

    if ( this->state->getHitPoints() == 0 ) {
        this->notify();
    }
}

void Unit::attack(Unit* enemy) {
    this->ability->attack(enemy);
}
void Unit::counterAttack(Unit* enemy) {
    this->ability->counterAttack(enemy);
}