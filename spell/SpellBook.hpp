#ifndef SPELL_BOOK_HPP
#define SPELL_BOOK_HPP

#include <map>
#include "Spell.hpp"
#include "Heal.hpp"
#include "FireBall.hpp"

enum Spells { heal, fireBall };

class SpellBook {
    protected:
        std::map<Spells, Spell*> spellsMap;
        static SpellBook* spellBook;

        SpellBook();

    public:
        virtual ~SpellBook();

        static SpellBook* getSpellBook();
        Spell* getSpell(Spells sp);
};

#endif //SPELL_BOOK_HPP