#include "MagicAbility.hpp"

MagicAbility::MagicAbility(SpellCaster* owner, Spell* spell)
    : owner(owner), spell(spell) {};

MagicAbility::~MagicAbility() {
    delete(this->spell);
}

void MagicAbility::changeSpell(Spell* newSpell) {
    delete(this->spell);
    this->spell = newSpell;
}

void MagicAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->spell->getCost());
    this->spell->action(enemy, 1);
}