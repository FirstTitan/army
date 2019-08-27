#ifndef BERSERKER_HPP
#define BERSERKER_HPP

#include "Unit.hpp"
#include "../state/BerserkerState.hpp"
#include "../ability/DefaultAbility.hpp"

class Berserker : public Unit {
    public:
        Berserker(const char* title, int hitPoints, int damage);
        virtual ~Berserker();
};

#endif //BERSERKER_HPP