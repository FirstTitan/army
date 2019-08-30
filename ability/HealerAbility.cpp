#include "HealerAbility.hpp"

HealerAbility::HealerAbility(SpellCaster* owner, Spells spell)
    : MagicAbility(owner, spell) {};

HealerAbility::~HealerAbility() {};

void HealerAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->spell->getCost());

    if ( this->spell->isCombat() ) {
        this->spell->action(enemy, 0.5);
    } else {
        this->spell->action(enemy, 1);
    }
}
