#ifndef WIZARD_ABILITY_HPP
#define WIZARD_ABILITY_HPP

#include "MagicAbility.hpp"

class WizardAbility : public MagicAbility {
    public:
        WizardAbility(SpellCaster* owner, Spells spell);
        virtual ~WizardAbility();

        virtual void cast(Unit* enemy);
};

#endif //WIZARD_ABILITY_HPP