#include "SpellBook.hpp"

SpellBook::SpellBook() {
    this->spellBook = this;
    this->spellsMap = {
        { heal, new Heal(30, 30) },
        { fireBall, new FireBall(30, 30) }
    };
}

SpellBook::~SpellBook() {};

SpellBook* SpellBook::getSpellBook() {
    if ( !spellBook ) {
        spellBook = new SpellBook();
    }
    return spellBook;
}

Spell* SpellBook::getSpell(Spells sp) {
    return this->spellsMap.at(sp);
}

SpellBook* SpellBook::spellBook = nullptr;