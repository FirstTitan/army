#include "Heal.hpp"

Heal::Heal(int actionPoints, int cost) : Spell(actionPoints, cost) {
    this->combat = false;
}

Heal::~Heal() {};

void Heal::action(Unit* target, float spellPower) {
    target->addHitPoints(this->getActionPoints()*spellPower);
}