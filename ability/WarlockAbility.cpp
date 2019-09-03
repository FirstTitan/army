#include "WarlockAbility.hpp"

WarlockAbility::WarlockAbility(SpellCaster* owner, Spells spell)
    : MagicAbility(owner, spell) {
        this->counterDemons = 0;
}

WarlockAbility::~WarlockAbility() {};

int WarlockAbility::getCounter() const {
    return this->counterDemons;
}

void WarlockAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();

    if ( this->owner->getCounter() == 0 ) {
        this->owner->spendMana(this->spell->getCost());
        if ( this->spell->isCombat() ) {
            this->spell->action(enemy, 1);
        } else {
            this->spell->action(enemy, 0.5);
        }
    } else {
        this->owner->spendMana(20*this->owner->getCounter());
        this->owner->notify(enemy);
    }
}

Demon* WarlockAbility::summonDemon() {
    if ( this->counterDemons < 3 ) {
        this->counterDemons += 1;

        Demon* demon = new Demon("Demon", 200, 20);
        this->owner->addObserver(demon);

        return demon;
    } else {
        throw OutOfDemonLimitException();
    }
}