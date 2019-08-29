#ifndef HEALER_ABILITY_HPP
#define HEALER_ABILITY_HPP

#include "MagicAbility.hpp"

class HealerAbility : public MagicAbility {
    public:
        HealerAbility(SpellCaster* owner, Spell* spell);
        virtual ~HealerAbility();

        virtual void cast(Unit* enemy);
};

#endif //HEALER_ABILITY_HPP