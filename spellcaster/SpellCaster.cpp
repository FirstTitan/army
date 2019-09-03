#include "SpellCaster.hpp"

SpellCaster::SpellCaster(const char* title, int hitPoints, int damage, int mana)
    : Unit(title, hitPoints, damage), magicState(new MagicState(mana)) {
        this->ability = new DefaultAbility(this);
        this->magicMan = true;
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
void SpellCaster::clearMagicAbility() {
    this->magicAbility = nullptr;
    this->notify();
    this->magicMan = false;
}

void SpellCaster::changeSpell(Spells newSpell) {
    this->magicAbility->changeSpell(newSpell);
}
void SpellCaster::cast(Unit* enemy) {
    this->magicAbility->cast(enemy);
}

int SpellCaster::getCounter() const {
    this->magicAbility->getCounter();
}

Demon* SpellCaster::summonDemon() {
    return this->magicAbility->summonDemon();
}

void SpellCaster::showMyself() {
    Unit::showMyself();
    if ( this->isMagicMan() ) {
        std::cout << "\nMana: " << this->getMana() << '/'
            << this->getManaLimit() << std::endl;
    }
}