#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../spellcaster/Healer.hpp"
#include "../unit/Soldier.hpp"

TEST_CASE( "Tests for Healer class" ) {
    Healer* healer = new Healer("Healer", 100, 10, 150);
    Soldier* enemy = new Soldier("Soldier", 150, 20);

    REQUIRE( healer->getTitle() == "Healer" );
    REQUIRE( healer->getHitPoints() == 100);
    REQUIRE( healer->getHitPointsLimit() == 100 );
    REQUIRE( healer->getDamage() == 10 );
    REQUIRE( healer->getMana() == 150 );
    REQUIRE( healer->getManaLimit() == 150 );

    REQUIRE( enemy->getTitle() == "Soldier" );
    REQUIRE( enemy->getHitPoints() == 150 );
    REQUIRE( enemy->getHitPointsLimit() == 150 );
    REQUIRE( enemy->getDamage() == 20 );

    healer->attack(enemy);
    REQUIRE( healer->getHitPoints() == 90 );
    REQUIRE( enemy->getHitPoints() == 140 );

    enemy->takeDamage(40);
    REQUIRE( enemy->getHitPoints() == 100 );

    healer->cast(enemy);
    REQUIRE( enemy->getHitPoints() == 130 );
    REQUIRE( healer->getHitPoints() == 90 );
    REQUIRE( healer->getMana() == 120 );

    healer->changeSpell(fireBall);

    healer->cast(enemy);
    REQUIRE( enemy->getHitPoints() == 115 );
    REQUIRE( healer->getHitPoints() == 90 );
    REQUIRE( healer->getMana() == 90 );

    healer->cast(enemy);
    healer->cast(enemy);
    healer->cast(enemy);

    REQUIRE( enemy->getHitPoints() == 70 );
    REQUIRE( healer->getHitPoints() == 90 );
    REQUIRE( healer->getMana() == 0 );

    try {
        healer->cast(enemy);
    } catch ( OutOfManaException ) {
        REQUIRE( healer->getMana() == 0 );
    }

    healer->addMana(50);
    REQUIRE( healer->getMana() == 50 );

    healer->addMana(300);
    REQUIRE( healer->getMana() == 150 );
}
