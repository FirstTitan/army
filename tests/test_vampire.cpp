#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../unit/Vampire.hpp"
#include "../unit/Soldier.hpp"
#include "../unit/Werewolf.hpp"

TEST_CASE( "Tests for Vampire class" ) {
    Vampire* vampire = new Vampire("Vampire", 200, 40);

    REQUIRE( vampire->getTitle() == "Vampire" );
    REQUIRE( vampire->getHitPoints() == 200 );
    REQUIRE( vampire->getHitPointsLimit() == 200 );
    REQUIRE( vampire->getDamage() == 40 );

    SECTION( "Vampire::takeDamage tests" ) {
        int damage = 10;
        int iterations = vampire->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            vampire->takeDamage(damage);
            int expectedHP = vampire->getHitPointsLimit() - damage * i;
            REQUIRE( vampire->getHitPoints() == expectedHP );
        }

        try {
            vampire->takeDamage(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }
    }

    SECTION( "Vampire::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = vampire->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            vampire->takeMagicDamage(damage);
            int expectedHP = vampire->getHitPointsLimit() - damage * i;
            REQUIRE( vampire->getHitPoints() == expectedHP );
        }

        try {
            vampire->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }
    }

    SECTION( "Vampire::addHitPoints tests" ) {
        vampire->takeDamage(50);
        REQUIRE( vampire->getHitPoints() == 150 );

        vampire->addHitPoints(40);
        REQUIRE( vampire->getHitPoints() == 190 );

        vampire->addHitPoints(10);
        REQUIRE( vampire->getHitPoints() == 200 );

        vampire->addHitPoints(10);
        REQUIRE( vampire->getHitPoints() == 200 );

        vampire->takeDamage(200);
        REQUIRE( vampire->getHitPoints() == 0 );

        try {
            vampire->addHitPoints(10);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }
    }

    SECTION( "Vampire::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 160, 20);

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 160 );
        REQUIRE( enemy->getHitPointsLimit() == 160 );
        REQUIRE( enemy->getDamage() == 20 );

        vampire->takeDamage(100);
        REQUIRE( vampire->getHitPoints() == 100 );

        vampire->attack(enemy);

        REQUIRE( vampire->getHitPoints() == 110 );
        REQUIRE( enemy->getHitPoints() == 120 );

        vampire->attack(enemy);
        vampire->attack(enemy);

        REQUIRE( vampire->getHitPoints() == 130 );
        REQUIRE( enemy->getHitPoints() == 40 );

        enemy->takeDamage(40);
        REQUIRE( enemy->getHitPoints() == 0 );

        try {
            vampire->attack(enemy);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( vampire->getHitPoints() == 130 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            enemy->attack(vampire);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( vampire->getHitPoints() == 130 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }
    }

    SECTION( "Vampire::counterAttack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 160, 20);

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 160 );
        REQUIRE( enemy->getHitPointsLimit() == 160 );
        REQUIRE( enemy->getDamage() == 20 );

        vampire->takeDamage(100);
        REQUIRE( vampire->getHitPoints() == 100 );

        vampire->counterAttack(enemy);

        REQUIRE( vampire->getHitPoints() == 110 );
        REQUIRE( enemy->getHitPoints() == 140 );

        vampire->counterAttack(enemy);
        vampire->counterAttack(enemy);
        vampire->counterAttack(enemy);

        REQUIRE( vampire->getHitPoints() == 140 );
        REQUIRE( enemy->getHitPoints() == 80 );

        enemy->takeDamage(80);
        REQUIRE( enemy->getHitPoints() == 0 );

        try {
            vampire->counterAttack(enemy);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( vampire->getHitPoints() == 140 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            enemy->counterAttack(vampire);
        } catch ( OutOfHitPointsException ) {
            REQUIRE( vampire->getHitPoints() == 140 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }
    }

    SECTION( "Vampire::turnToVampire tests" ) {
        Soldier* soldier = new Soldier("Soldier", 150, 20);

        REQUIRE( soldier->getTitle() == "Soldier" );
        REQUIRE( soldier->getHitPoints() == 150 );
        REQUIRE( soldier->getHitPointsLimit() == 150 );
        REQUIRE( soldier->getDamage() == 20 );
        REQUIRE( soldier->isVampire() == false );
        REQUIRE( soldier->isUndead() == false );

        vampire->turnToVampire(soldier);

        REQUIRE( (std::string)soldier->getTitle() == "Vampire" );
        REQUIRE( soldier->getHitPoints() == 200 );
        REQUIRE( soldier->getHitPointsLimit() == 200 );
        REQUIRE( soldier->getDamage() == 30 );
        REQUIRE( soldier->isVampire() == true );
        REQUIRE( soldier->isUndead() == true );

        Werewolf* werewolf = new Werewolf("Werewolf", 190, 25);

        REQUIRE( werewolf->getTitle() == "Werewolf" );
        REQUIRE( werewolf->getHitPoints() == 190 );
        REQUIRE( werewolf->getHitPointsLimit() == 190 );
        REQUIRE( werewolf->getDamage() == 25 );
        REQUIRE( werewolf->isVampire() == false );
        REQUIRE( werewolf->isUndead() == false );

        vampire->turnToVampire(werewolf);

        REQUIRE( werewolf->getTitle() == "Werewolf" );
        REQUIRE( werewolf->getHitPoints() == 190 );
        REQUIRE( werewolf->getHitPointsLimit() == 190 );
        REQUIRE( werewolf->getDamage() == 25 );
        REQUIRE( werewolf->isVampire() == false );
        REQUIRE( werewolf->isUndead() == false );
    }
}