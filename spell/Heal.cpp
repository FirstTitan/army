#include "Heal.hpp"

Heal::Heal(int actionPoints, int cost) : Spell(actionPoints, cost) {};
Heal::~Heal() {};

void Heal::action(Unit* target) {
    target->addHitPoints(this->getActionPoints());
}