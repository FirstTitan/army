#ifndef WARLOCK_ABILITY_HPP
#define WARLOCK_ABILITY_HPP

#include "MagicAbility.hpp"
#include "../exceptions.hpp"

class WarlockAbility : public MagicAbility {
    protected:
        int counterDemons;

    public:
        WarlockAbility(SpellCaster* owner, Spells spell);
        virtual ~WarlockAbility();

        virtual int getCounter() const;

        virtual void cast(Unit* enemy);

        virtual Demon* summonDemon();
};

#endif //WARLOCK_ABILITY_HPP