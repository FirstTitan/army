#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../unit/Werewolf.hpp"
#include "../unit/Soldier.hpp"

TEST_CASE( "Tests for Werewolf class" ) {
    Werewolf* werewolf = new Werewolf("Werewolf", 200, 20);

    REQUIRE( werewolf->getTitle() == "Werewolf" );
    REQUIRE( werewolf->getHitPoints() == 200 );
    REQUIRE( werewolf->getHitPointsLimit() == 200 );
    REQUIRE( werewolf->getDamage() == 20 );

    SECTION( "Werewolf::takeDamage tests" ) {
        int damage = 20;
        int iterations = werewolf->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            werewolf->takeDamage(damage);
            int expectedHP = werewolf->getHitPointsLimit() - damage * i;
            REQUIRE( werewolf->getHitPoints() == expectedHP );
        }

        try {
            werewolf->takeDamage(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::takeDamage for wolf tests" ) {
        werewolf->turnWolf();

        REQUIRE( werewolf->getTitle() == "Werewolf" );
        REQUIRE( werewolf->getHitPoints() == 400 );
        REQUIRE( werewolf->getHitPointsLimit() == 400 );
        REQUIRE( werewolf->getDamage() == 40 );

        int damage = 40;
        int iterations = werewolf->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            werewolf->takeDamage(damage);
            int expectedHP = werewolf->getHitPointsLimit() - damage * i;
            REQUIRE( werewolf->getHitPoints() == expectedHP );
        }

        try {
            werewolf->takeDamage(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::takeMagicDamage tests" ) {
        int damage = 20;
        int iterations = werewolf->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            werewolf->takeMagicDamage(damage);
            int expectedHP = werewolf->getHitPointsLimit() - damage * i;
            REQUIRE( werewolf->getHitPoints() == expectedHP );
        }

        try {
            werewolf->takeDamage(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::takeMagicDamage for wolf tests" ) {
        werewolf->turnWolf();

        int damage = 40;
        int iterations = werewolf->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            werewolf->takeMagicDamage(damage/2);
            int expectedHP = werewolf->getHitPointsLimit() - damage * i;
            REQUIRE( werewolf->getHitPoints() == expectedHP );
        }

        try {
            werewolf->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::addHitPoints tests" ) {
        werewolf->takeDamage(50);
        REQUIRE( werewolf->getHitPoints() == 150 );

        werewolf->addHitPoints(40);
        REQUIRE( werewolf->getHitPoints() == 190 );

        werewolf->addHitPoints(10);
        REQUIRE( werewolf->getHitPoints() == 200 );

        werewolf->addHitPoints(10);
        REQUIRE( werewolf->getHitPoints() == 200 );

        werewolf->takeDamage(200);
        REQUIRE( werewolf->getHitPoints() == 0 );

        try {
            werewolf->addHitPoints(10);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 200, 20);

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 200 );
        REQUIRE( enemy->getHitPointsLimit() == 200 );
        REQUIRE( enemy->getDamage() == 20 );

        werewolf->attack(enemy);

        REQUIRE( werewolf->getHitPoints() == 190 );
        REQUIRE( enemy->getHitPoints() == 180 );

        werewolf->attack(enemy);
        werewolf->attack(enemy);
        werewolf->attack(enemy);

        REQUIRE( werewolf->getHitPoints() == 160 );
        REQUIRE( enemy->getHitPoints() == 120 );

        enemy->takeDamage(120);
        REQUIRE( enemy->getHitPoints() == 0 );

        try {
            werewolf->attack(enemy);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( werewolf->getHitPoints() == 160 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            enemy->attack(werewolf);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( werewolf->getHitPoints() == 160 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::attack for wolf tests" ) {
        Soldier* enemy = new Soldier("Enemy", 200, 20);

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 200 );
        REQUIRE( enemy->getHitPointsLimit() == 200 );
        REQUIRE( enemy->getDamage() == 20 );

        werewolf->turnWolf();

        werewolf->attack(enemy);

        REQUIRE( werewolf->getHitPoints() == 390 );
        REQUIRE( enemy->getHitPoints() == 160 );

        werewolf->attack(enemy);
        werewolf->attack(enemy);
        werewolf->attack(enemy);

        REQUIRE( werewolf->getHitPoints() == 360 );
        REQUIRE( enemy->getHitPoints() == 40 );

        enemy->takeDamage(40);

        try {
            werewolf->attack(enemy);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( werewolf->getHitPoints() == 360 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            werewolf->attack(enemy);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( werewolf->getHitPoints() == 360 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::turnBack test" ) {
        werewolf->turnWolf();
        REQUIRE( werewolf->getHitPoints() == 400 );

        werewolf->turnBack();
        REQUIRE( werewolf->getHitPoints() == 200 );
    }
}
