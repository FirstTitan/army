#ifndef UNIT_HPP
#define UNIT_HPP

#include <iomanip>
#include "../state/State.hpp"
#include "../ability/Ability.hpp"
#include "../interface/Observable.hpp"

class Ability;

class Unit : public Observable {
    protected:
        State* state;
        Ability* ability;
        bool undead;
        bool vampire;
        bool werewolf;
        bool magicMan;

    public:
        Unit(const char* title, int hitPoints, int damage);
        virtual ~Unit();

        void ensureIsAlive();

        bool isUndead() const;
        bool isVampire() const;
        bool isWerewolf() const;
        bool isMagicMan() const;

        void setUndead(Unit* unit, bool flag);
        void setVampire(Unit* unit, bool flag);
        void setWerewolf(Unit* unit, bool flag);

        void setAbility(Ability* ability);
        void setState(State* state);

        const char* getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;

        void addHitPoints(int hp);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        virtual void turn(Unit* unit);

        virtual void showMyself();
};

#endif //UNIT_HPP