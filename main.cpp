#include <iostream>
#include "Army.hpp"

int main() {
    Warlock* war = new Warlock("Warlock", 100, 10, 150);

    war->showMyself();

    return 0;
}
