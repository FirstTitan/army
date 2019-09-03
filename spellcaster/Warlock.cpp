#include "Warlock.hpp"

Warlock::Warlock(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana) {
        this->magicAbility = new WarlockAbility(this, fireBall);
}

Warlock::~Warlock() {};

void Warlock::showMyself() {
    Unit::showMyself();
    if ( this->isMagicMan() ) {
        std::cout << "Mana: " << this->getMana() << '/' << this->getManaLimit()
            << "\nThe number of my demons: " << this->getNumberObservers() << std::endl;
    }
}