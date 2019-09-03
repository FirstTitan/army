#ifndef WARLOCK_ABILITY_HPP
#define WARLOCK_ABILITY_HPP

#include "MagicAbility.hpp"
#include "../exceptions.hpp"

class WarlockAbility : public MagicAbility {
    public:
        WarlockAbility(SpellCaster* owner, Spells spell);
        virtual ~WarlockAbility();

        virtual void cast(Unit* enemy);

        virtual Demon* summonDemon();
};

#endif //WARLOCK_ABILITY_HPP