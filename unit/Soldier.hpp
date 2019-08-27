#ifndef SOLDIER_HPP
#define SOLDIER_HPP

#include "Unit.hpp"
#include "../ability/DefaultAbility.hpp"

class Soldier : public Unit {
    public:
        Soldier(const char* title, int hitPoints, int damage);
        virtual ~Soldier();
};

#endif //SOLDIER_HPP