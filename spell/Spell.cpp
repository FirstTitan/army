#include "Spell.hpp"

Spell::Spell(int actionPoints, int cost)
    : actionPoints(actionPoints), cost(cost) {
        this->combat = false;
}

Spell::~Spell() {};

bool Spell::isCombat() {
    return this->combat;
}

int Spell::getActionPoints() const {
    return this->actionPoints;
}
int Spell::getCost() const {
    return this->cost;
}