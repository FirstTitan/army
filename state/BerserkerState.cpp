#include "BerserkerState.hpp"
#include <iostream>

BerserkerState::BerserkerState(const char* title, int hitPoints, int damage) 
: State(title, hitPoints, damage) {};
BerserkerState::~BerserkerState() {};

void BerserkerState::ensureIsAlive() {
    this->ensureIsAlive();
}

const char* BerserkerState::getTitle() const {
    return this->getTitle();
}
int BerserkerState::getHitPoints() const {
    return this->getHitPoints();
}
int BerserkerState::getHitPointsLimit() const {
    return this->getHitPointsLimit();
}
int BerserkerState::getDamage() const {
    return this->getDamage();
}

void BerserkerState::addHitPoints(int hp) {
    return this->addHitPoints(hp);
}
void BerserkerState::takeDamage(int dmg) {
    return this->takeDamage(dmg);
}
void BerserkerState::takeMagicDamage(int dmg) {
    std::cout << "Your magic nothing" << std::endl;
}