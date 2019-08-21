#ifndef SPELL_HPP
#define SPELL_HPP

#include "../unit/Unit.hpp"

class Spell {
    protected:
        int actionPoints;
        int cost;

    public:
        Spell(int actionPoints, int cost);
        virtual ~Spell();

        int getActionPoints() const;
        int getCost() const;

        virtual void action(Unit* target) = 0;
};

#endif //SPELL_HPP