#ifndef WEREWOLF_HPP
#define WEREWOLF_HPP

#include "../unit/Unit.hpp"
#include "../ability/DefaultAbility.hpp"
#include "../state/WerewolfState.hpp"
#include "../state/State.hpp"

class Werewolf : public Unit {
    private:
        const char* title;
        int hitPointsLimit;
        int damage;
    public:
        Werewolf(const char* title, int hitPoints, int damage);
        virtual ~Werewolf();

        void turnWolf();
        void turnBack();

        void turnToWerewolf(Unit* unit);
};

#endif //WEREWOLF_HPP