#include "NecromancerAbility.hpp"

NecromancerAbility::NecromancerAbility(SpellCaster* owner, Spells spell)
    : MagicAbility(owner, spell) {};

NecromancerAbility::~NecromancerAbility() {};

void NecromancerAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->spell->getCost());

    if ( this->spell->isCombat() ) {
        this->spell->action(enemy, 1.5);
    } else {
        this->spell->action(enemy, 0.5);
    }
}