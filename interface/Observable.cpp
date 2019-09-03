#include "Observable.hpp"
#include <iostream>

Observable::Observable() {};
Observable::~Observable() {};

int Observable::getNumberObservers() const {
    return this->observers.size();
}

void Observable::addObserver(Observer* obs) {
    observers.insert(obs);
}

void Observable::removeObserver(Observer* obs) {
    this->observers.erase(obs);
}
void Observable::checkAliveObservers() {
    std::set<Observer*>::iterator it = this->observers.begin();
    for ( ; it != this->observers.end(); it++ ) {
            (*it)->update(this, checkAlive);
    }
}

void Observable::notify() {
    std::set<Observer*>::iterator it = this->observers.begin();
    for ( ; it != this->observers.end(); it++ ) {
        (*it)->update(this, isObservable);
    }
}

void Observable::notify(Observable* obs) {
    std::set<Observer*>::iterator it = this->observers.begin();
    for ( ; it != this->observers.end(); it++ ) {
        (*it)->update(obs, isNotObservable);
    }
}
