#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include "SpellCaster.hpp"
#include "../ability/WarlockAbility.hpp"
#include "../unit/Demon.hpp"
#include "../exceptions.hpp"

class Warlock : public SpellCaster {
    public:
        Warlock(const char* title, int hitPoints, int damage, int mana);
        virtual ~Warlock();

        virtual void showMyself();
};

#endif //WARLOCK_HPP