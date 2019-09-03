#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../spellcaster/Warlock.hpp"
#include "../unit/Soldier.hpp"
#include "../unit/Vampire.hpp"
#include "../unit/Werewolf.hpp"

TEST_CASE( "Tests for Warlock class" ) {
    Warlock* warlock = new Warlock("Warlock", 100, 10, 150);

    REQUIRE( warlock->getTitle() == "Warlock" );
    REQUIRE( warlock->getHitPoints() == 100 );
    REQUIRE( warlock->getHitPointsLimit() == 100 );
    REQUIRE( warlock->getDamage() == 10 );
    REQUIRE( warlock->getMana() == 150 );
    REQUIRE( warlock->getManaLimit() == 150 );

    SECTION( "Warlock::cast tests" ) {
        Soldier* soldier = new Soldier("Soldier", 200, 20);

        REQUIRE( soldier->getTitle() == "Soldier" );
        REQUIRE( soldier->getHitPoints() == 200 );
        REQUIRE( soldier->getHitPointsLimit() == 200 );
        REQUIRE( soldier->getDamage() == 20 );

        warlock->cast(soldier);
        REQUIRE( warlock->getHitPoints() == 100 );
        REQUIRE( warlock->getMana() == 120 );
        REQUIRE( soldier->getHitPoints() == 170 );

        warlock->cast(soldier);
        warlock->cast(soldier);
        warlock->cast(soldier);
        warlock->cast(soldier);

        REQUIRE( warlock->getHitPoints() == 100 );
        REQUIRE( warlock->getMana() == 0 );
        REQUIRE( soldier->getHitPoints() == 50 );

        try {
            warlock->cast(soldier);
        } catch ( OutOfManaException ) {
            REQUIRE( warlock->getHitPoints() == 100 );
            REQUIRE( warlock->getMana() == 0 );
            REQUIRE( soldier->getHitPoints() == 50 );
        }
    }

    SECTION( "Warlock::changeSpell tests" ) {
        warlock->changeSpell(heal);

        Soldier* soldier = new Soldier("Soldier", 200, 20);

        soldier->takeDamage(150);
        REQUIRE( soldier->getHitPoints() == 50 );

        warlock->cast(soldier);
        REQUIRE( warlock->getMana() == 120 );
        REQUIRE( soldier->getHitPoints() == 65 );

        warlock->cast(soldier);
        warlock->cast(soldier);
        warlock->cast(soldier);
        warlock->cast(soldier);

        REQUIRE( warlock->getMana() == 0 );
        REQUIRE( soldier->getHitPoints() == 125 );

        try {
            warlock->cast(soldier);
        } catch ( OutOfManaException ) {
            REQUIRE( warlock->getMana() == 0 );
            REQUIRE( soldier->getHitPoints() == 125 );
        }
    }

    SECTION( "Warlock::summonDemon/cast tests" ) {
        Soldier* soldier = new Soldier("Soldier", 200, 20);
        Demon* demon = warlock->summonDemon();

        REQUIRE( (std::string)demon->getTitle() == "Demon" );
        REQUIRE( demon->getHitPoints() == 200 );
        REQUIRE( demon->getHitPointsLimit() == 200 );
        REQUIRE( demon->getDamage() == 20 );
        REQUIRE( warlock->getNumberObservers() == 1 );

        Demon* demon2 = warlock->summonDemon();
        REQUIRE( warlock->getNumberObservers() == 2 );

        Demon* demon3 = warlock->summonDemon();
        REQUIRE( warlock->getNumberObservers() == 3 );

        try {
            Demon* demon4 = warlock->summonDemon();
        } catch ( OutOfDemonLimitException ) {
            REQUIRE( warlock->getNumberObservers() == 3 );
        }

        warlock->cast(soldier);

        REQUIRE( warlock->getMana() == 90 );
        REQUIRE( soldier->getHitPoints() == 140 );
        REQUIRE( demon->getHitPoints() == 190 );
        REQUIRE( demon2->getHitPoints() == 190 );
        REQUIRE( demon3->getHitPoints() == 190 );

        demon2->takeDamage(190);

        warlock->cast(soldier);

        REQUIRE( warlock->getMana() == 50 );
        REQUIRE( soldier->getHitPoints() == 100 );
        REQUIRE( demon->getHitPoints() == 180 );
        REQUIRE( demon2->getHitPoints() == 0 );
        REQUIRE( demon3->getHitPoints() == 180 );

        demon->takeDamage(180);
        demon3->takeDamage(180);

        REQUIRE( demon->getHitPoints() == 0 );
        REQUIRE( demon3->getHitPoints() == 0 );

        warlock->cast(soldier);

        REQUIRE( soldier->getHitPoints() == 70 );
        REQUIRE( warlock->getMana() == 20 );
    }

    SECTION( "Warlock::summonDemon with Vampire" ) {
        Vampire* vampire = new Vampire("Vampire", 200, 40);
        Demon* demon = warlock->summonDemon();

        REQUIRE( vampire->getTitle() == "Vampire" );
        REQUIRE( vampire->getHitPoints() == 200 );
        REQUIRE( vampire->getHitPointsLimit() == 200 );
        REQUIRE( vampire->getDamage() == 40 );

        vampire->turn(warlock);

        REQUIRE( (std::string)warlock->getTitle() == "Vampire" );
        REQUIRE( warlock->getHitPoints() == 200 );
        REQUIRE( warlock->getHitPointsLimit() == 200 );
        REQUIRE( warlock->getDamage() == 30 );

        //all magicAbility is not working and it's good!!!

        demon->attack(warlock);
        demon->attack(warlock);

        REQUIRE( demon->getHitPoints() == 170 );
        REQUIRE( warlock->getHitPoints() == 174 );

        warlock->attack(vampire);

        REQUIRE( vampire->getHitPoints() == 180 );
        REQUIRE( warlock->getHitPoints() == 169 );
    }

    SECTION( "Warlock::summonDemon with Werewolf" ) {
        Warlock* warlock2 = new Warlock("Warlock", 100, 10, 150);
        Werewolf* werewolf = new Werewolf("Werewolf", 200, 20);
        Demon* demon = warlock->summonDemon();

        REQUIRE( warlock2->getTitle() == "Warlock" );
        REQUIRE( warlock2->getHitPoints() == 100 );
        REQUIRE( warlock2->getHitPointsLimit() == 100 );
        REQUIRE( warlock2->getDamage() == 10 );
        REQUIRE( warlock2->getMana() == 150 );
        REQUIRE( warlock2->getManaLimit() == 150 );

        REQUIRE( werewolf->getTitle() == "Werewolf" );
        REQUIRE( werewolf->getHitPoints() == 200 );
        REQUIRE( werewolf->getHitPointsLimit() == 200 );
        REQUIRE( werewolf->getDamage() == 20 );

        REQUIRE( (std::string)demon->getTitle() == "Demon" );
        REQUIRE( demon->getHitPoints() == 200 );
        REQUIRE( demon->getHitPointsLimit() == 200 );
        REQUIRE( demon->getDamage() == 20 );

        werewolf->turn(warlock);

        REQUIRE( (std::string)warlock->getTitle() == "Werewolf" );
        REQUIRE( warlock->getHitPoints() == 200 );
        REQUIRE( warlock->getHitPointsLimit() == 200 );
        REQUIRE( warlock->getDamage() == 20 );

        warlock2->cast(warlock);

        REQUIRE( warlock2->getHitPoints() == 100 );
        REQUIRE( warlock->getHitPoints() == 170 );

        warlock->turnMyself();

        REQUIRE( (std::string)warlock->getTitle() == "Hulk" );
        REQUIRE( warlock->getHitPoints() == 340 );
        REQUIRE( warlock->getHitPointsLimit() == 400 );
        REQUIRE( warlock->getDamage() == 40 );

        warlock2->cast(warlock);

        REQUIRE( warlock2->getHitPoints() == 100 );
        REQUIRE( warlock->getHitPoints() == 280 );

        warlock->attack(warlock2);

        REQUIRE( warlock2->getHitPoints() == 60 );
        REQUIRE( warlock->getHitPoints() == 275 );

        warlock->turnMyself();

        REQUIRE( (std::string)warlock->getTitle() == "Werewolf" );
        REQUIRE( warlock->getHitPoints() == 137 );
        REQUIRE( warlock->getHitPointsLimit() == 200 );
        REQUIRE( warlock->getDamage() == 20 );

        warlock->attack(warlock2);

        REQUIRE( warlock2->getHitPoints() == 40 );
        REQUIRE( warlock->getHitPoints() == 132 );
    }
}