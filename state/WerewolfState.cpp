#include "WerewolfState.hpp"

WerewolfState::WerewolfState(const char* title, int hitPointsLimit, int hitPoints, int damage)
    : State(title, hitPointsLimit*2, hitPoints*2, damage*2) {};

WerewolfState::~WerewolfState() {};

void WerewolfState::takeMagicDamage(int dmg) {
    this->ensureIsAlive();

    int total = dmg * 2;
    if ( total > this->hitPoints ) {
        this->hitPoints = 0;
    }
    this->hitPoints -= total;
}