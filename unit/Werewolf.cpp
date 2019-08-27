#include "Werewolf.hpp"

Werewolf::Werewolf(const char* title, int hitPoints, int damage)
    : Unit(title, hitPoints, damage) {
        this->ability = new DefaultAbility(this);
        this->title = title;
        this->hitPointsLimit = hitPoints;
        this->damage = damage;
}

Werewolf::~Werewolf() {};

void Werewolf::turnWolf() {
    this->state = new WerewolfState(this->getTitle(), this->getHitPoints(), this->getDamage());
}
void Werewolf::turnBack() {
    this->state = new State(this->title, this->hitPointsLimit, this->damage);
    //when he turn back, he has full hitPoints
}