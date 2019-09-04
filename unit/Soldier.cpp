#include "Soldier.hpp"

Soldier::Soldier(const char* title, int hitPoints, int damage)
    : Unit(title, hitPoints, damage) {
        this->ability = new DefaultAbility(this);
}
Soldier::~Soldier() {};
