#ifndef HEALER_HPP
#define HEALER_HPP

#include "SpellCaster.hpp"
#include "../ability/HealerAbility.hpp"
#include "../spell/Heal.hpp"

class Healer : public SpellCaster {
    public:
        Healer(const char* title, int hitPoints, int damage, int mana);
        virtual ~Healer();
};

#endif //HEALER_HPP