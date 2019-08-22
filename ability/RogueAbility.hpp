#ifndef ROGUE_ABILITY_HPP
#define ROGUE_ABILITY_HPP

#include "Ability.hpp"

class RogueAbility : public Ability {
    public:
        RogueAbility(Unit* owner);
        virtual ~RogueAbility();

        virtual void attack(Unit* enemy);
};

#endif //ROGUE_ABILITY_HPP
