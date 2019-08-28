#ifndef PRIEST_HPP
#define PRIEST_HPP

#include "SpellCaster.hpp"
#include "../ability/PriestAbility.hpp"
#include "../spell/Heal.hpp"

class Priest : public SpellCaster {
    public:
        Priest(const char* title, int hitPoints, int damage, int mana);
        virtual ~Priest();
};

#endif //PRIEST_HPP