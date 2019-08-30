#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../spellcaster/Necromancer.hpp"
#include "../unit/Soldier.hpp"

TEST_CASE( "Tests for Necromancer class" ) {
    Necromancer* nec = new Necromancer("Necromancer", 150, 12, 150);

    REQUIRE( nec->getTitle() == "Necromancer" );
    REQUIRE( nec->getHitPoints() == 150 );
    REQUIRE( nec->getHitPointsLimit() == 150 );
    REQUIRE( nec->getDamage() == 12 );
    REQUIRE( nec->getMana() == 150 );
    REQUIRE( nec->getManaLimit() == 150 );

    SECTION( "Necromancer::attack tests" ) {
        Soldier* soldier1 = new Soldier("Kolyan", 200, 20);
        Soldier* soldier2 = new Soldier("Vovan", 180, 30);

        nec->attack(soldier1);
        REQUIRE( nec->getHitPoints() == 140 );
        REQUIRE( soldier1->getHitPoints() == 188 );

        nec->attack(soldier1);
        nec->attack(soldier1);
        nec->attack(soldier1);

        REQUIRE( nec->getHitPoints() == 110 );
        REQUIRE( soldier1->getHitPoints() == 152 );

        soldier2->attack(nec);
        REQUIRE( nec->getHitPoints() == 80 );
        REQUIRE( soldier2->getHitPoints() == 174 );

        soldier1->takeDamage(152);
        soldier2->takeDamage(174);

        REQUIRE( soldier1->getHitPoints() == 0 );
        REQUIRE( soldier2->getHitPoints() == 0 );
        REQUIRE( nec->getHitPoints() == 100 );

        try {
            nec->attack(soldier1);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( nec->getHitPoints() == 100 );
            REQUIRE( soldier1->getHitPoints() == 0 );
        }

        try {
            soldier1->attack(nec);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( nec->getHitPoints() == 100 );
            REQUIRE( soldier1->getHitPoints() == 0 );
        }
    }

    SECTION( "Necromancer::cast tests" ) {
        Soldier* soldier1 = new Soldier("Kolyan", 200, 20);
        Soldier* soldier2 = new Soldier("Vovan", 180, 30);
        Soldier* soldier3 = new Soldier("Monster", 250, 40);

        nec->cast(soldier1);
        REQUIRE( nec->getHitPoints() == 150 );
        REQUIRE( nec->getMana() == 120 );
        REQUIRE( soldier1->getHitPoints() == 155 );

        nec->cast(soldier3);
        REQUIRE( nec->getHitPoints() == 150 );
        REQUIRE( nec->getMana() == 90 );
        REQUIRE( soldier3->getHitPoints() == 205 );

        soldier1->attack(nec);
        soldier2->attack(nec);
        soldier3->attack(nec);

        REQUIRE( nec->getHitPoints() == 60 );
        REQUIRE( soldier1->getHitPoints() == 149 );
        REQUIRE( soldier2->getHitPoints() == 174 );
        REQUIRE( soldier3->getHitPoints() == 199 );

        nec->cast(soldier1);
        nec->cast(soldier1);
        nec->cast(soldier1);

        REQUIRE( nec->getHitPoints() == 60 );
        REQUIRE( nec->getMana() == 0 );
        REQUIRE( soldier1->getHitPoints() == 14 );

        try {
            nec->cast(soldier1);
        } catch ( OutOfManaException ) {
            REQUIRE( nec->getHitPoints() == 60 );
            REQUIRE( nec->getMana() == 0 );
            REQUIRE( soldier1->getHitPoints() == 14 );
        }

        soldier1->takeDamage(14);
        soldier2->takeDamage(174);
        soldier3->takeDamage(199);

        REQUIRE( soldier1->getHitPoints() == 0 );
        REQUIRE( soldier2->getHitPoints() == 0 );
        REQUIRE( soldier3->getHitPoints() == 0 );

        REQUIRE( nec->getHitPoints() == 105 );
    }

    SECTION( "Necromancer::changeSpell tests" ) {
        nec->changeSpell(heal);

        Soldier* soldier = new Soldier("Soldier", 200, 20);

        soldier->takeDamage(170);
        REQUIRE( soldier->getHitPoints() == 30 );

        nec->cast(soldier);
        REQUIRE( nec->getHitPoints() == 150 );
        REQUIRE( nec->getMana() == 120 );
        REQUIRE( soldier->getHitPoints() == 45 );

        nec->cast(soldier);
        nec->cast(soldier);
        nec->cast(soldier);
        nec->cast(soldier);

        REQUIRE( nec->getHitPoints() == 150 );
        REQUIRE( nec->getMana() == 0 );
        REQUIRE( soldier->getHitPoints() == 105 );

        try {
            nec->cast(soldier);
        } catch ( OutOfManaException ) {
            REQUIRE( nec->getMana() == 0 );
            REQUIRE( soldier->getHitPoints() == 105 );
        }
    }
}