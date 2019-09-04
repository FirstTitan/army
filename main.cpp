#include <iostream>
#include "Army.hpp"

int main() {
    Soldier* soldier = new Soldier("Soldier", 180, 20);
    Rogue* rogue = new Rogue("Rogue", 150, 20);
    Berserker* berserker = new Berserker("Berserker", 120, 20);
    Vampire* vampire = new Vampire("Vampire", 110, 30);
    Werewolf* werewolf = new Werewolf("Werewolf", 150, 20);

    Wizard* wizard = new Wizard("Wizard", 100, 10, 150);
    Healer* healer = new Healer("Healer", 100, 10, 150);
    Priest* priest = new Priest("Priest", 100, 10, 150);
    Warlock* warlock = new Warlock("Warlock", 100, 10, 150);
    Necromancer* necromancer = new Necromancer("Necromanacer", 100, 10, 150);

    Demon* demon1 = warlock->summonDemon();
    Demon* demon2 = warlock->summonDemon();
    Demon* demon3 = warlock->summonDemon();

    warlock->cast(wizard); 

    warlock->showMyself();
    std::cout << "--------------" << std::endl;
    wizard->showMyself();
    std::cout << std::endl;

    priest->cast(wizard);
    wizard->showMyself();
    std::cout << "--------------" << std::endl;
    priest->showMyself();
    std::cout << std::endl;

    demon1->takeDamage(200);
    demon1->showMyself();
    std::cout << std::endl;

    warlock->cast(wizard);

    warlock->showMyself();
    std::cout << "--------------" << std::endl;
    wizard->showMyself();
    std::cout << std::endl;

    werewolf->turn(warlock);
    warlock->showMyself();
    std::cout << std::endl;

    warlock->turnMyself();
    warlock->showMyself();
    std::cout << std::endl;

    try {
        warlock->attack(wizard);
    } catch ( OutOfHitPointsException ) {
        warlock->showMyself();
        std::cout << "--------------" << std::endl;
        wizard->showMyself();
        std::cout << std::endl;
    }

    necromancer->cast(warlock);
    warlock->showMyself();
    std::cout << "--------------" << std::endl;
    necromancer->showMyself();
    std::cout << std::endl;

    warlock->attack(necromancer);
    warlock->showMyself();
    std::cout << "--------------" << std::endl;
    necromancer->showMyself();
    std::cout << std::endl;

    warlock->turnMyself();
    warlock->showMyself();
    std::cout << std::endl;

    warlock->takeDamage(200);
    warlock->showMyself();
    std::cout << "--------------" << std::endl;
    necromancer->showMyself();
    std::cout << std::endl;

    vampire->turn(necromancer);
    necromancer->showMyself();
    std::cout << std::endl;

    priest->changeSpell(fireBall);
    priest->cast(necromancer);

    priest->showMyself();
    std::cout << "--------------" << std::endl;
    necromancer->showMyself();
    std::cout << std::endl;

    healer->cast(necromancer);
    healer->showMyself();
    std::cout << "--------------" << std::endl;
    necromancer->showMyself();
    std::cout << std::endl;

    priest->cast(berserker);
    priest->showMyself();
    std::cout << "--------------" << std::endl;
    berserker->showMyself();
    std::cout << std::endl;

    rogue->attack(soldier);
    rogue->showMyself();
    std::cout << "--------------" << std::endl;
    soldier->showMyself();

    delete(soldier);
    delete(rogue);
    delete(berserker);
    delete(vampire);
    delete(werewolf);

    delete(wizard);
    delete(healer);
    delete(priest);
    delete(warlock);
    delete(necromancer);

    delete(demon1);
    delete(demon2);
    delete(demon3);

    return 0;
}
