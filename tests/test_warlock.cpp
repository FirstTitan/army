#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../spellcaster/Warlock.hpp"
#include "../unit/Soldier.hpp"

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

        warlock->cast(soldier);

        REQUIRE( warlock->getMana() == 30 );
        REQUIRE( soldier->getHitPoints() == 80 );
        REQUIRE( demon->getHitPoints() == 180 );
        REQUIRE( demon2->getHitPoints() == 180 );
        REQUIRE( demon3->getHitPoints() == 180 );
    }
}