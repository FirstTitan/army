#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>

#include "../exceptions.hpp"

class State {
    protected:
        const char* title;
        int hitPoints;
        int hitPointsLimit;
        int damage;

        void _takeDamage(int dmg);

    public:
        State(const char *title, int hitPoints, int damage);
        State(const char *title, int hitPointsLimit, int hitPoints, int damage);
        virtual ~State();

        void ensureIsAlive();

        const char* getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;

        void addHitPoints(int hp);
        void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);
};

#endif //STATE_HPP