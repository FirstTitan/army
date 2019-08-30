#include "MagicAbility.hpp"

MagicAbility::MagicAbility(SpellCaster* owner, Spells spell)
    : owner(owner) {
        this->spell = SpellBook::getSpellBook()->getSpell(spell);
}

MagicAbility::~MagicAbility() {
    delete(this->spell);
}

void MagicAbility::changeSpell(Spells newSpell) {
    delete(this->spell);
    this->spell = SpellBook::getSpellBook()->getSpell(newSpell);
}

void MagicAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->spell->getCost());
    this->spell->action(enemy, 1);
}