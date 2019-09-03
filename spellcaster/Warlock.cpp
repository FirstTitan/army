#include "Warlock.hpp"

Warlock::Warlock(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana) {
        this->magicAbility = new WarlockAbility(this, fireBall);
}

Warlock::~Warlock() {};

void Warlock::showMyself() {
    Unit::showMyself();
    // std::cout << "Name: " << this->getTitle() << "\nHit points: " << this->getHitPoints()
    //     << '/' << this->getHitPointsLimit() << "\nDamage: " << this->getDamage() << std::endl;
    if ( this->isMagicMan() ) {
        std::cout << "Mana: " << this->getMana() << '/' << this->getManaLimit()
            << "\nThe number of my demons: " << this->getCounter() << std::endl;
    }
}