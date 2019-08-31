#ifndef DEMON_HPP
#define DEMON_HPP

#include "Soldier.hpp"
#include "../interface/Observer.hpp"

class Demon : public Soldier, public Observer {
    protected:
        static int total;
        int id;

    public:
        Demon(const char* title, int hitPoints, int damage);
        virtual ~Demon();

        int getID() const;

        virtual void update(Observable* obs);

        virtual void showMyself();
};

#endif //DEMON_HPP