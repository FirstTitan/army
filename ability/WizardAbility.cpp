#include "WizardAbility.hpp"

WizardAbility::WizardAbility(SpellCaster* owner, Spell* spell)
    : MagicAbility(owner, spell) {};

WizardAbility::~WizardAbility() {};

void WizardAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->spell->getCost());

    if ( this->spell->isCombat() ) {
        this->spell->action(enemy, 1);
    } else {
        this->spell->action(enemy, 0.5);
    }
}
