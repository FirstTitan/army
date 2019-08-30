#ifndef WEREWOLF_STATE_HPP
#define WEREWOLF_STATE_HPP

#include "State.hpp"

class WerewolfState : public State {
    public:
        WerewolfState(const char* title, int hitPointsLimit, int hitPoints, int damage);
        virtual ~WerewolfState();

        virtual void takeMagicDamage(int dmg);
};

#endif //WEREWOLF_STATE_HPP