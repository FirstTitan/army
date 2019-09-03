#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "Observable.hpp"

class Observable;

enum StateObserver { checkAlive, isObservable, isNotObservable };

class Observer {
    protected:
        Observer();

    public:
        virtual ~Observer();

        virtual void update(Observable* obs, StateObserver state) = 0;
};

#endif //OBSERVER_HPP