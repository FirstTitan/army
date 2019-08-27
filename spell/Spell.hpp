#ifndef SPELL_HPP
#define SPELL_HPP

#include <iostream>
#include "../unit/Unit.hpp"

class Spell {
    protected:
        int actionPoints;
        int cost;
        bool combat;

    public:
        Spell(int actionPoints, int cost);
        virtual ~Spell();

        bool isCombat();

        int getActionPoints() const;
        int getCost() const;

        virtual void action(Unit* target, float spellPower) = 0;
};

#endif //SPELL_HPP