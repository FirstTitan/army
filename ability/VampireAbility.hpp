#ifndef VAMPIRE_ABILITY_HPP
#define VAMPIRE_ABILITY_HPP

#include "Ability.hpp"
#include "../unit/Unit.hpp"

class VampireAbility : public Ability {
    public:
        VampireAbility(Unit* owner);
        virtual ~VampireAbility();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        virtual void turn(Unit* unit);
};

#endif //VAMPIRE_ABILITY_HPP