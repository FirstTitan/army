#ifndef MAGIC_STATE_HPP
#define MAGIC_STATE_HPP

#include "../exceptions.hpp"

class MagicState {
    protected:
        int mana;
        int manaLimit;

    public:
        MagicState(int mana);
        virtual ~MagicState();

        int getMana() const;
        int getManaLimit() const;

        void addMana(int extra);
        void spendMana(int cost);
};

#endif //MAGIC_STATE_HPP