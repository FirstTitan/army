#ifndef BERSERKER_STATE_HPP
#define BERSERKER_STATE_HPP

#include <iostream>
#include "State.hpp"

class BerserkerState : public State {
    public:
        BerserkerState(const char* title, int hitPoints, int damage);
        virtual ~BerserkerState();

        void ensureIsAlive();

        const char* getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;

        void addHitPoints(int hp);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);
};

#endif //BERSERKER_STATE_HPP