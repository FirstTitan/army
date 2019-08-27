#ifndef HEAL_HPP
#define HEAL_HPP

#include "Spell.hpp"

class Heal : public Spell {
    public:
        Heal(int actionPoints, int cost);
        virtual ~Heal();

        virtual void action(Unit* target);
};

#endif //HEAL_HPP