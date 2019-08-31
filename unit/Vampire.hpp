#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Unit.hpp"
#include "../ability/VampireAbility.hpp"

class Vampire : public Unit {
    public:
        Vampire(const char* title, int hitPoints, int damage);
        virtual ~Vampire();
};

#endif //VAMPIRE_HPP