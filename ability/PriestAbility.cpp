#include "PriestAbility.hpp"

PriestAbility::PriestAbility(SpellCaster* owner, Spells spell)
    : MagicAbility(owner, spell) {};

PriestAbility::~PriestAbility() {};

void PriestAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->spell->getCost());

    if ( this->spell->isCombat() ) {
        if ( enemy->isUndead() ) {
            this->spell->action(enemy, 2);
            return;
        }
        this->spell->action(enemy, 0.5);
    } else {
        this->spell->action(enemy, 1);
    }
}