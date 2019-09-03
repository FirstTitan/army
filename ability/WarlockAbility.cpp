#include "WarlockAbility.hpp"

WarlockAbility::WarlockAbility(SpellCaster* owner, Spells spell)
    : MagicAbility(owner, spell) {};

WarlockAbility::~WarlockAbility() {};

void WarlockAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();

    if ( this->owner->getNumberObservers() == 0 ) {
        this->owner->spendMana(this->spell->getCost());
        if ( this->spell->isCombat() ) {
            this->spell->action(enemy, 1);
        } else {
            this->spell->action(enemy, 0.5);
        }
    } else {
        this->owner->checkAliveObservers();
        this->owner->spendMana(20*this->owner->getNumberObservers());
        this->owner->notify(enemy);
    }
}

Demon* WarlockAbility::summonDemon() {
    if ( this->owner->getNumberObservers() < 3 ) {
        Demon* demon = new Demon("Demon", 200, 20);
        this->owner->addObserver(demon);

        return demon;
    } else {
        throw OutOfDemonLimitException();
    }
}