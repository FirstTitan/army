#include "Wizard.hpp"

Wizard::Wizard(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana) {
        this->magicAbility = new WizardAbility(this, fireBall);
}
Wizard::~Wizard() {};
