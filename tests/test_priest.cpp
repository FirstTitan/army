#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../spellcaster/Priest.hpp"
#include "../spell/FireBall.hpp"
#include "../unit/Soldier.hpp"
#include "../unit/Vampire.hpp"

TEST_CASE( "Tests for Priest class" ) {
    Priest* priest = new Priest("Priest", 100, 10, 150);
    Soldier* soldier = new Soldier("Soldier", 150, 20);
    Vampire* vampire = new Vampire("Vampire", 200, 30);

    REQUIRE( priest->getTitle() == "Priest" );
    REQUIRE( priest->getHitPoints() == 100 );
    REQUIRE( priest->getHitPointsLimit() == 100 );
    REQUIRE( priest->getDamage() == 10 );
    REQUIRE( priest->getMana() == 150 );
    REQUIRE( priest->getManaLimit() == 150 );

    REQUIRE( soldier->getTitle() == "Soldier" );
    REQUIRE( soldier->getHitPoints() == 150 );
    REQUIRE( soldier->getHitPointsLimit() == 150 );
    REQUIRE( soldier->getDamage() == 20 );

    REQUIRE( vampire->getTitle() == "Vampire" );
    REQUIRE( vampire->getHitPoints() == 200 );
    REQUIRE( vampire->getHitPointsLimit() == 200 );
    REQUIRE( vampire->getDamage() == 30 );

    SECTION( "Priest::attack/cast tests" ) {
        priest->attack(soldier);
        REQUIRE( priest->getHitPoints() == 90 );
        REQUIRE( soldier->getHitPoints() == 140 );

        priest->attack(vampire);
        REQUIRE( priest->getHitPoints() == 75 );
        REQUIRE( vampire->getHitPoints() == 197 );

        soldier->takeDamage(40);
        vampire->takeDamage(40);
        REQUIRE( soldier->getHitPoints() == 100 );
        REQUIRE( vampire->getHitPoints() == 157 );

        priest->cast(soldier);
        REQUIRE( priest->getHitPoints() == 75 );
        REQUIRE( priest->getMana() == 120 );
        REQUIRE( soldier->getHitPoints() == 130 );

        priest->cast(vampire);
        REQUIRE( priest->getHitPoints() == 75 );
        REQUIRE( priest->getMana() == 90 );
        REQUIRE( vampire->getHitPoints() == 187 );

        priest->cast(vampire);
        priest->cast(vampire);
        priest->cast(soldier);

        REQUIRE( priest->getHitPoints() == 75 );
        REQUIRE( priest->getMana() == 0 );
        REQUIRE( soldier->getHitPoints() == 150 );
        REQUIRE( vampire->getHitPoints() == 200 );

        try {
            priest->cast(vampire);
        } catch ( OutOfManaException ) {
            REQUIRE( priest->getMana() == 0 );
        }
    }

    SECTION( "Priest::changeSpell/cast/addMana tests" ) {
        priest->changeSpell(new FireBall(30, 30));

        priest->cast(soldier);
        REQUIRE( priest->getHitPoints() == 100 );
        REQUIRE( priest->getMana() == 120 );
        REQUIRE( soldier->getHitPoints() == 135 );

        priest->cast(vampire);
        REQUIRE( priest->getHitPoints() == 100 );
        REQUIRE( priest->getMana() == 90 );
        REQUIRE( vampire->getHitPoints() == 140 );

        priest->addMana(30);
        REQUIRE( priest->getMana() == 120 );

        priest->addMana(100);
        REQUIRE( priest->getMana() == 150 );
    }
}