#include "Warlock.hpp"

Warlock::Warlock(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana) {
        this->magicAbility = new WarlockAbility(this, fireBall);
        this->counterDemons = 0;
}

Warlock::~Warlock() {};

int Warlock::getCounter() const {
    return this->counterDemons;
}

Demon* Warlock::summonDemon() {
    if ( this->counterDemons < 3 ) {
        this->counterDemons += 1;

        Demon* demon = new Demon("Demon", 200, 20);
        this->addObserver(demon);

        return demon;
    } else {
        throw OutOfDemonLimitException();
    }
}

void Warlock::showMyself() {
    std::cout << "Name: " << this->getTitle() << "\nHit points: " << this->getHitPoints()
        << '/' << this->getHitPointsLimit() << "\nDamage: " << this->getDamage()
        << "\nMana: " << this->getMana() << '/' << this->getManaLimit()
        << "\nThe number of my demons: " << this->getCounter() << std::endl;
}