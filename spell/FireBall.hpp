#ifndef FIRE_BALL_HPP
#define FIRE_BALL_HPP

#include "Spell.hpp"

class FireBall : public Spell {
    public:
        FireBall(int actionPoints, int cost);
        virtual ~FireBall();

        virtual void action(Unit* target, float spellPower);
};

#endif //FIRE_BALL_HPP