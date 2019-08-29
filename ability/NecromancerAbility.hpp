#ifndef NECROMANCER_ABILITY_HPP
#define NECROMANCER_ABILITY_HPP

#include "MagicAbility.hpp"

class NecromancerAbility : public MagicAbility {
    public:
        NecromancerAbility(SpellCaster* owner, Spell* spell);
        virtual ~NecromancerAbility();

        virtual void cast(Unit* enemy);
};

#endif //NECROMANCER_ABILITY_HPP