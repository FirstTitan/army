#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions.h"

class State {
    protected:
        const char* title;
        int hitPoints;
        int hitPointsLimit;
        int damage;

        void _takeDamage(int dmg);

    public:
        State(const char* title, int hitPoints, int damage);
        virtual ~State();

        void ensureIsAlive();

        const char* getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;

        void addHitPoints(int hp);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);
};

#endif // STATE_H
