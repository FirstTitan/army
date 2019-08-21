#include "SpellCaster.hpp"

SpellCaster::SpellCaster(const char* title, int hitPoints, int damage, int mana)
    : Unit(title, hitPoints, damage), magicState(new MagicState(mana)) {
        this->ability = new DefaultAbility(this);
        //I think it's error!!!**************************************************

}
SpellCaster::~SpellCaster() {
    delete(this->magicState);
    delete(this->magicAbility);
}

int SpellCaster::getMana() const {
    return this->magicState->getMana();
}
int SpellCaster::getManaLimit() const {
    return this->magicState->getManaLimit();
}

void SpellCaster::addMana(int extra) {
    this->magicState->addMana(extra);
}
void SpellCaster::spendMana(int cost) {
    this->magicState->spendMana(cost);
}

void SpellCaster::changeSpell(Spell* newSpell) {
    this->magicAbility->changeSpell(newSpell);
}
void SpellCaster::cast(Unit* enemy) {
    this->magicAbility->cast(enemy);
}