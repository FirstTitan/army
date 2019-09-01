#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "../unit/Unit.hpp"

class Unit;

class Ability {
    protected:
        Unit *owner;
    public:
        Ability(Unit *owner);
        virtual ~Ability();

        virtual void attack(Unit *enemy) = 0;
        virtual void counterAttack(Unit *enemy);

        virtual void turn(Unit* unit);
        virtual void turnMyself();
};

#endif //ABILITY_HPP