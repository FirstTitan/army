#ifndef NECROMANCER_ABILITY_HPP
#define NECROMANCER_ABILITY_HPP

#include "MagicAbility.hpp"
#include "../spellcaster/Necromancer.hpp"

class NecromancerAbility : public MagicAbility {
    public:
        NecromancerAbility(SpellCaster* owner, Spells spell);
        virtual ~NecromancerAbility();

        virtual void cast(Unit* enemy);
};

#endif //NECROMANCER_ABILITY_HPP