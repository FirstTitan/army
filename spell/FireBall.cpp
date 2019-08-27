#include "FireBall.hpp"

FireBall::FireBall(int actionPoints, int cost) : Spell(actionPoints, cost) {
    this->combat = true;
}

FireBall::~FireBall() {};

void FireBall::action(Unit* target, float spellPower) {
    target->takeMagicDamage(this->getActionPoints()*spellPower);
}
