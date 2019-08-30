#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../spellcaster/Wizard.hpp"
#include "../unit/Soldier.hpp"

TEST_CASE( "Tests for Wizard class" ) {
    Wizard* wizard = new Wizard("Wizard", 100, 10, 150);
    Soldier* enemy = new Soldier("Enemy", 150, 20);

    REQUIRE( enemy->getTitle() == "Enemy" );
    REQUIRE( enemy->getHitPoints() == 150 );
    REQUIRE( enemy->getHitPointsLimit() == 150 );
    REQUIRE( enemy->getDamage() == 20 );

    REQUIRE( wizard->getTitle() == "Wizard" );
    REQUIRE( wizard->getHitPoints() == 100 );
    REQUIRE( wizard->getHitPointsLimit() == 100 );
    REQUIRE( wizard->getDamage() == 10 );
    REQUIRE( wizard->getMana() == 150 );
    REQUIRE( wizard->getManaLimit() == 150 );

    wizard->attack(enemy);
    REQUIRE( enemy->getHitPoints() == 140 );
    REQUIRE( wizard->getHitPoints() == 90 );

    wizard->cast(enemy);
    REQUIRE( enemy->getHitPoints() == 110 );
    REQUIRE( wizard->getHitPoints() == 90 );
    REQUIRE( wizard->getMana() == 120 );

    wizard->changeSpell(heal);
    wizard->cast(enemy);
    REQUIRE( enemy->getHitPoints() == 125 );
    REQUIRE( wizard->getHitPoints() == 90 );
    REQUIRE( wizard->getMana() == 90 );

    wizard->cast(enemy);
    wizard->cast(enemy);
    wizard->cast(enemy);

    REQUIRE( enemy->getHitPoints() == 150 );
    REQUIRE( wizard->getHitPoints() == 90 );
    REQUIRE( wizard->getMana() == 0 );

    try {
        wizard->cast(enemy);
    } catch ( OutOfManaException ) {
        REQUIRE( wizard->getMana() == 0 );
    }

    wizard->addMana(50);
    REQUIRE( wizard->getMana() == 50 );

    wizard->addMana(300);
    REQUIRE( wizard->getMana() == 150 );
}
