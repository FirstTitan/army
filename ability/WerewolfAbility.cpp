#include "WerewolfAbility.hpp"

WerewolfAbility::WerewolfAbility(Unit* unit) : Ability(unit) {
    if ( unit->isWerewolf() ) {
        this->name = unit->getTitle();
    } else {
        this->name = "Werewolf";
    }
}
WerewolfAbility::~WerewolfAbility() {};

void WerewolfAbility::attack(Unit* enemy) {
    this->Ability::attack(enemy);
}

void WerewolfAbility::turn(Unit* enemy) {
    if ( !enemy->isVampire() && !enemy->isWerewolf() ) {
        enemy->setAbility(new WerewolfAbility(enemy));
        enemy->setState(new State(this->name, 200, 20));
        enemy->setWerewolf(enemy, true);
        enemy->setUndead(enemy, false);
        if ( enemy->isMagicMan() ) {
            ((SpellCaster*)(enemy))->clearMagicAbility();
        }
    }
}
void WerewolfAbility::turnMyself() {
    this->owner->ensureIsAlive();

    if ( !this->owner->isWolf() ) {
        this->owner->setWolf(this->owner, true);
        this->owner->setState(new WerewolfState("Hulk", this->owner->getHitPointsLimit(), this->owner->getHitPoints(), this->owner->getDamage()));
    } else {
        this->owner->setWolf(this->owner, false);
        this->owner->setState(new State(this->name, this->owner->getHitPointsLimit()/2, this->owner->getHitPoints()/2, this->owner->getDamage()/2));
    }
}