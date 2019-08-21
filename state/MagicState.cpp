#include "MagicState.hpp"

MagicState::MagicState(int mana)
    : mana(mana), manaLimit(mana) {};

MagicState::~MagicState() {};

int MagicState::getMana() const {
    return this->mana;
}
int MagicState::getManaLimit() const {
    return this->manaLimit;
}

void MagicState::addMana(int extra) {
    int total = this->mana + extra;

    if ( total > this->manaLimit ) {
        this->mana = this->manaLimit;
        return;
    }
    this->mana = total;
}
void MagicState::spendMana(int cost) {
    if ( cost > this->mana ) {
        throw OutOfManaException();
    }
    this->mana -= cost;
}