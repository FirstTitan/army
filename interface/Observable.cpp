#include "Observable.hpp"

#include <iostream>

Observable::Observable() {};
Observable::~Observable() {};

void Observable::addObserver(Observer* obs) {
    observers.insert(obs);
}

void Observable::removeObserver(Observer* obs) {
    this->observers.erase(obs);
}

void Observable::notify() {
    std::set<Observer*>::iterator it = this->observers.begin();
    for ( ; it != this->observers.end(); it++ ) {
        (*it)->update(this, true);
    }
}

void Observable::notify(Observable* obs) {
    std::set<Observer*>::iterator it = this->observers.begin();
    for ( ; it != this->observers.end(); it++ ) {
        (*it)->update(obs, false);
    }
}
