#include "Demon.hpp"

Demon::Demon(const char* title, int hitPoints, int damage)
    : Soldier(title, hitPoints, damage) {};

Demon::~Demon() {};

void Demon::update(Observable* obs, bool isObservable) {
    if ( isObservable && (((Unit*)(obs))->isWerewolf() || ((Unit*)(obs))->isVampire()) ) {
        obs->removeObserver(this);
    } else if ( isObservable && ((Unit*)(obs))->getHitPoints() == 0 ) {
        obs->removeObserver(this);
    } else {
        this->attack((Unit*)obs);
    }
}
