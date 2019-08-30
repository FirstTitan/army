#ifndef MAGIC_ABILITY_HPP
#define MAGIC_ABILITY_HPP

#include "../spell/Spell.hpp"
#include "../spellcaster/SpellCaster.hpp"
#include "../spell/SpellBook.hpp"

class SpellCaster;

class MagicAbility {
    protected:
        SpellCaster* owner;
        Spell* spell;

    public:
        MagicAbility(SpellCaster* owner, Spells spell);
        virtual ~MagicAbility();

        void changeSpell(Spells newSpell);
        virtual void cast(Unit* enemy);
};

#endif //MAGIC_ABILITY_HPP