#ifndef WARLOCK_ABILITY_HPP
#define WARLOCK_ABILITY_HPP

#include "MagicAbility.hpp"

class WarlockAbility : public MagicAbility {
    public:
        WarlockAbility(SpellCaster* owner, Spells spell);
        virtual ~WarlockAbility();

        virtual void cast(Unit* enemy);
};

#endif //WARLOCK_ABILITY_HPP