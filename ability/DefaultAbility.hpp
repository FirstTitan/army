#ifndef DEFAULT_ABILITY_HPP
#define DEFAULT_ABILITY_HPP

#include "Ability.hpp"

class DefaultAbility : public Ability {
    public:
        DefaultAbility(Unit* owner);
        virtual ~DefaultAbility();

        virtual void attack(Unit* enemy);
};

#endif //DEFAULT_ABILITY_HPP