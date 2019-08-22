#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../unit/Soldier.hpp"

TEST_CASE( "Test for Soldier class" ) {
    Soldier* soldier = new Soldier("Soldier", 150, 20);

    REQUIRE( soldier->getTitle() == "Soldier" );
    REQUIRE( soldier->getHitPoints() == 150 );
    REQUIRE( soldier->getHitPointsLimit() == 150 );
    REQUIRE( soldier->getDamage() == 20 );

    SECTION( "Soldier::takeDamage tests" ) {
        int damage = 10;
        int iterations = soldier->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            soldier->takeDamage(damage);
            int expectedHP = soldier->getHitPointsLimit() - damage * i;
            REQUIRE( soldier->getHitPoints() == expectedHP );
        }

        try {
            soldier->takeDamage(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( soldier->getHitPoints() == 0 );
        }

        try {
            soldier->addHitPoints(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( soldier->getHitPoints() == 0 );
        }
    }

    SECTION( "Soldier::takeMagicDamage tests") {
        int damage = 10;
        int iterations = soldier->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            soldier->takeMagicDamage(damage);
            int expectedHP = soldier->getHitPointsLimit() - damage * i;
            REQUIRE( soldier->getHitPoints() == expectedHP );
        }

        try {
            soldier->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( soldier->getHitPoints() == 0 );
        }

        try {
            soldier->addHitPoints(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( soldier->getHitPoints() == 0 );
        }
    }

    SECTION( "Soldier::addHitPoints tests" ) {
        soldier->takeDamage(50);
        REQUIRE( soldier->getHitPoints() == 100 );

        soldier->addHitPoints(40);
        REQUIRE( soldier->getHitPoints() == 140 );

        soldier->addHitPoints(10);
        REQUIRE( soldier->getHitPoints() == 150 );

        soldier->addHitPoints(10);
        REQUIRE( soldier->getHitPoints() == 150 );
    }

    SECTION( "Soldier::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getDamage() == 20 );

        soldier->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 130 );
        REQUIRE( soldier->getHitPoints() == 140 );

        soldier->attack(enemy);
        soldier->attack(enemy);
        soldier->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 70 );
        REQUIRE( soldier->getHitPoints() == 110 );

        enemy->takeDamage(60);

        REQUIRE( enemy->getHitPoints() == 10 );

        try {
            soldier->attack(enemy);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( soldier->getHitPoints() == 110);
        }

        try {
            enemy->attack(soldier);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( soldier->getHitPoints() == 110 );
        }
    }
}