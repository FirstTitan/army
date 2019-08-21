#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../state/MagicState.hpp"

TEST_CASE( "Test for MagicState class" ) {
    MagicState* state = new MagicState(100);

    REQUIRE( state->getMana() == 100 );
    REQUIRE( state->getManaLimit() == 100 );

    SECTION( "MagicState::spendMana tests" ) {
        int cost = 10;
        int iterations = state->getManaLimit() / cost;

        for ( int i = 1; i <= iterations; i++ ) {
            state->spendMana(cost);
            int expectedHP = state->getManaLimit() - cost * i;
            REQUIRE( state->getMana() == expectedHP );
        }

        try {
            state->spendMana(cost);
        } catch ( OutOfManaException ) {
            REQUIRE( state->getMana() == 0 );
        }

        try {
            state->addMana(cost);
        } catch ( OutOfManaException ) {
            REQUIRE( state->getMana() == 0 );
        }
    }

    SECTION( "MagicState::addMana tests" ) {
        state->spendMana(50);
        REQUIRE( state->getMana() == 50 );

        state->addMana(40);
        REQUIRE( state->getMana() == 90 );

        state->addMana(10);
        REQUIRE( state->getMana() == 100 );

        state->addMana(10);
        REQUIRE( state->getMana() == 100 );
    }
}