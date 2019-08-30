#include "Werewolf.hpp"

Werewolf::Werewolf(const char* title, int hitPoints, int damage)
    : Unit(title, hitPoints, damage) {
        this->ability = new DefaultAbility(this);
        this->title = title;
        this->hitPointsLimit = hitPoints;
        this->damage = damage;
        this->werewolf = true;
}

Werewolf::~Werewolf() {};

void Werewolf::turnWolf() {
    this->state = new WerewolfState("Hulk", this->getHitPointsLimit(), this->getHitPoints(), this->getDamage());
}
void Werewolf::turnBack() {
    this->state = new State(this->title, this->hitPointsLimit, this->getHitPoints()/2, this->damage);
}

void Werewolf::turnToWerewolf(Unit* unit) {
    if ( !unit->isVampire() ) {
        delete(unit);
        unit = new Werewolf("Werewolf", 200, 20);
        unit->setWerewolf(unit, true);
        unit->setUndead(unit, false);
    }
}