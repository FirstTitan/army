#ifndef UNIT_HPP
#define UNIT_HPP

#include "../state/State.hpp"
#include "../ability/Ability.hpp"

class Ability;

class Unit {
    protected:
        State* state;
        Ability* ability;
        bool undead;

    public:
        Unit(const char* title, int hitPoints, int damage);
        virtual ~Unit();

        void ensureIsAlive();

        bool isUndead() const;

        const char* getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;

        void addHitPoints(int hp);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif //UNIT_HPP