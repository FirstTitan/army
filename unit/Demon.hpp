#ifndef DEMON_HPP
#define DEMON_HPP

#include "Soldier.hpp"
#include "../interface/Observer.hpp"

class Demon : public Soldier, public Observer {
    public:
        Demon(const char* title, int hitPoints, int damage);
        virtual ~Demon();

        virtual void update(Observable* obs, bool isObservable);
};

#endif //DEMON_HPP