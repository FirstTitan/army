#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <set>
#include "Observer.hpp"

class Observer;

class Observable {
    protected:
        std::set<Observer*> observers;

        Observable();
    public:
        virtual ~Observable();

        void addObserver(Observer* obs);
        void removeObserver(Observer* obs);

        virtual void notify();
        virtual void notify(Observable* obs);
};

#endif //OBSERVABLE_HPP