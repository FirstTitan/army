#ifndef WEREWOLF_ABILITY_HPP
#define  WEREWOLF_ABILITY_HPP

#include "Ability.hpp"
#include "../state/WerewolfState.hpp"

class WerewolfAbility : public Ability {
    protected:
        const char* name;

    public:
        WerewolfAbility(Unit* unit);
        virtual ~WerewolfAbility();

        virtual void attack(Unit* enemy);

        virtual void turn(Unit* enemy);
        virtual void turnMyself();
};

#endif //WEREWOLF_ABILITY_HPP