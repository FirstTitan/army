#ifndef ROGUE_HPP
#define ROGUE_HPP

#include "Unit.hpp"
#include "../ability/RogueAbility.hpp"

class Rogue : public Unit {
    public:
        Rogue(const char* title, int hitPoints, int damage);
        virtual ~Rogue();
};

#endif //ROGUE_HPP