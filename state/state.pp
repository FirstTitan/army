#include "State.h"

State::State(const char* title, int hitPoints, int damage) {
    this->title = title;
    this->hitPoints = hitPoints;
    this->hitPointsLimit = hitPoints;
    this->damage = damage;
}

State::~State() {}

void State::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
        throw OutOfHitPointsException();
    }
}

const char* State::getTitle() const {
    return this->title;
}

int State::getHitPoints() const {
    return this->hitPoints;
}

int State::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

int State::getDamage() const {
    return this->damage;
}

void State::addHitPoints(int hp) {
    this->ensureIsAlive();

    int total = this->hitPoints + hp;
    if ( total > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
        return;
    }
    this->hitPoints = total;
}

void State::_takeDamage(int dmg) {
    this->ensureIsAlive();

    if ( dmg > this->hitPoints ) {
        this->hitPoints = 0;
        return;
    }
    this->hitPoints -= dmg;
}

void State::takeDamage(int dmg) {
    this->_takeDamage(dmg);
}

void State::takeMagicDamage(int dmg) {
    this->_takeDamage(dmg);
}
