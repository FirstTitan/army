#include "Necromancer.hpp"

Necromancer::Necromancer(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana) {
    this->magicAbility = new NecromancerAbility(this, fireBall);
    this->undead = true;
}

Necromancer::~Necromancer() {};

void Necromancer::attack(Unit* enemy) {
    this->ability->attack(enemy);
    enemy->addObserver(this);
}

void Necromancer::cast(Unit* enemy) {
    this->magicAbility->cast(enemy);
    enemy->addObserver(this);
}

void Necromancer::update(Observable* obs) {
    this->addHitPoints(((Unit*)(obs))->getHitPointsLimit()/10);
    obs->removeObserver(this);
}