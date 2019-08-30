#include "Demon.hpp"

Demon::Demon(const char* title, int hitPoints, int damage)
    : Soldier(title, hitPoints, damage) {
        total += 1;
        this->id = total;
}

Demon::~Demon() {};

int Demon::getID() const {
    return this->id;
}

void Demon::update(Observable* obs) {
    this->attack((Unit*)obs);
}

int Demon::total = 0;