#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "Observable.hpp"

class Observable;

class Observer {
    protected:
        Observer();

    public:
        virtual ~Observer();

        virtual void update(Observable* obs, bool isObservable) = 0;
};

#endif //OBSERVER_HPP