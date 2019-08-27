#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../unit/Berserker.hpp"

TEST_CASE( "Tests for Berserker class" ) {
    Berserker* berserker = new Berserker("Berserker", 150, 20);

    REQUIRE( berserker->getTitle() == "Berserker" );
    REQUIRE( berserker->getHitPoints() == 150 );
    REQUIRE( berserker->getHitPointsLimit() == 150 );
    REQUIRE( berserker->getDamage() == 20 );

    SECTION( "Berserker::takeDamage tests" ) {
        int damage = 10;
        int iterations = berserker->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            berserker->takeDamage(damage);
            int expectedHP = berserker->getHitPointsLimit() - damage * i;
            REQUIRE( berserker->getHitPoints() == expectedHP );
        }

        try {
            berserker->takeDamage(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( berserker->getHitPoints() == 0 );
        }
    }

    SECTION( "Berserker::takeMagicDamage tests" ) {
        REQUIRE( berserker->getHitPoints() == 150 );

        berserker->takeMagicDamage(50);
        REQUIRE( berserker->getHitPoints() == 150 );
    }

    SECTION( "Berserker::addHitPoints tests" ) {
        berserker->takeDamage(50);
        REQUIRE( berserker->getHitPoints() == 100 );

        berserker->addHitPoints(40);
        REQUIRE( berserker->getHitPoints() == 140 );

        berserker->addHitPoints(10);
        REQUIRE( berserker->getHitPoints() == 150 );

        berserker->addHitPoints(10);
        REQUIRE( berserker->getHitPoints() == 150 );

        berserker->takeDamage(150);
        REQUIRE( berserker->getHitPoints() == 0 );

        try {
            berserker->addHitPoints(10);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( berserker->getHitPoints() == 0 );
        }
    }
}