#include "Demon.hpp"

Demon::Demon(const char* title, int hitPoints, int damage)
    : Soldier(title, hitPoints, damage) {};

Demon::~Demon() {};

void Demon::update(Observable* obs) {
    this->attack((Unit*)obs);
}
