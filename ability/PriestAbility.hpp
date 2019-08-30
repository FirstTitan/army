#ifndef PRIEST_ABILITY_HPP
#define PRIEST_ABILITY_HPP

#include "MagicAbility.hpp"

class PriestAbility : public MagicAbility {
    public:
        PriestAbility(SpellCaster* owner, Spells spell);
        virtual ~PriestAbility();

        virtual void cast(Unit* enemy);
};

#endif //PRIEST_ABILITY_HPP