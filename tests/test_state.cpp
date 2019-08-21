#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../state/State.hpp"

TEST_CASE( "Test for State class" ) {
    State* state = new State("State", 150, 20);

    REQUIRE( state->getTitle() == "State" );
    REQUIRE( state->getHitPoints() == 150 );
    REQUIRE( state->getHitPointsLimit() == 150 );
    REQUIRE( state->getDamage() == 20 );

    SECTION( "State::takeDamage tests" ) {
        int damage = 10;
        int iterations = state->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            state->takeDamage(damage);
            int expectedHP = state->getHitPointsLimit() - damage * i;
            REQUIRE( state->getHitPoints() == expectedHP );
        }

        try {
            state->takeDamage(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( state->getHitPoints() == 0 );
        }

        try {
            state->addHitPoints(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( state->getHitPoints() == 0 );
        }
    }

    SECTION( "State::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = state->getHitPointsLimit() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            state->takeMagicDamage(damage);
            int expectedHP = state->getHitPointsLimit() - damage * i;
            REQUIRE( state->getHitPoints() == expectedHP );
        }

        try {
            state->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( state->getHitPoints() == 0 );
        }

        try {
            state->addHitPoints(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( state->getHitPoints() == 0 );
        }
    }

    SECTION( "State::addHitPoints tests" ) {
        state->takeDamage(50);
        REQUIRE( state->getHitPoints() == 100 );

        state->addHitPoints(40);
        REQUIRE( state->getHitPoints() == 140 );

        state->addHitPoints(10);
        REQUIRE( state->getHitPoints() == 150 );

        state->addHitPoints(10);
        REQUIRE( state->getHitPoints() == 150 );
    }
}
