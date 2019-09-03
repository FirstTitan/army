#include "Werewolf.hpp"

Werewolf::Werewolf(const char* title, int hitPoints, int damage)
    : Unit(title, hitPoints, damage) {
        this->ability = new WerewolfAbility(this);
        this->werewolf = true;
}

Werewolf::~Werewolf() {};
