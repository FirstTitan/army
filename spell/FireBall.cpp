#include "FireBall.hpp"

FireBall::FireBall(int actionPoints, int cost) : Spell(actionPoints, cost) {};
FireBall::~FireBall() {};

void FireBall::action(Unit* target) {
    target->takeMagicDamage(this->getActionPoints());
}