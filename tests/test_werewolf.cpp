#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../unit/Werewolf.hpp"
#include "../unit/Soldier.hpp"
#include "../spellcaster/Necromancer.hpp"
#include "../unit/Vampire.hpp"

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
        werewolf->turnMyself();

        REQUIRE( (std::string)werewolf->getTitle() == "Hulk" );
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
        werewolf->turnMyself();

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

        werewolf->turnMyself();

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

    SECTION( "Werewolf::turnMyself test" ) {
        Soldier* soldier = new Soldier("Soldier", 200, 20);

        REQUIRE( soldier->getTitle() == "Soldier" );
        REQUIRE( soldier->getHitPoints() == 200 );
        REQUIRE( soldier->getHitPointsLimit() == 200 );
        REQUIRE( soldier->getDamage() == 20 );

        REQUIRE( werewolf->getTitle() == "Werewolf" );
        REQUIRE( werewolf->getHitPoints() == 200 );
        REQUIRE( werewolf->getHitPointsLimit() == 200 );
        REQUIRE( werewolf->getDamage() == 20 );

        werewolf->turnMyself();

        REQUIRE( (std::string)werewolf->getTitle() == "Hulk" );
        REQUIRE( werewolf->getHitPoints() == 400 );
        REQUIRE( werewolf->getHitPointsLimit() == 400 );
        REQUIRE( werewolf->getDamage() == 40 );

        soldier->attack(werewolf);
        REQUIRE( soldier->getHitPoints() == 180 );
        REQUIRE( werewolf->getHitPoints() == 380 );

        werewolf->turnMyself();

        REQUIRE( (std::string)werewolf->getTitle() == "Werewolf" );
        REQUIRE( werewolf->getHitPoints() == 190 );
        REQUIRE( werewolf->getHitPointsLimit() == 200 );
        REQUIRE( werewolf->getDamage() == 20 );
    }

    SECTION( "Werewolf::turn tests" ) {
        Necromancer* nec = new Necromancer("Necromancer", 150, 12, 150);

        REQUIRE( nec->getTitle() == "Necromancer" );
        REQUIRE( nec->getHitPoints() == 150 );
        REQUIRE( nec->getHitPointsLimit() == 150 );
        REQUIRE( nec->getDamage() == 12 );
        REQUIRE( nec->getMana() == 150 );
        REQUIRE( nec->getManaLimit() == 150 );
        REQUIRE( nec->isWerewolf() == false );
        REQUIRE( nec->isUndead() == true );

        werewolf->turn(nec);

        REQUIRE( (std::string)nec->getTitle() == "Werewolf" );
        REQUIRE( nec->getHitPoints() == 200 );
        REQUIRE( nec->getHitPointsLimit() == 200 );
        REQUIRE( nec->getDamage() == 20 );
        REQUIRE( nec->isWerewolf() == true );
        REQUIRE( nec->isUndead() == false );

        Soldier* soldier = new Soldier("Soldier", 180, 15);

        nec->turn(soldier);

        REQUIRE( (std::string)soldier->getTitle() == "Werewolf" );
        REQUIRE( soldier->getHitPoints() == 200 );
        REQUIRE( soldier->getHitPointsLimit() == 200 );
        REQUIRE( soldier->getDamage() == 20 );

        soldier->turnMyself();

        REQUIRE( (std::string)soldier->getTitle() == "Hulk" );
        REQUIRE( soldier->getHitPoints() == 400 );
        REQUIRE( soldier->getHitPointsLimit() == 400 );
        REQUIRE( soldier->getDamage() == 40 );

        soldier->turnMyself();

        REQUIRE( (std::string)soldier->getTitle() == "Werewolf" );
        REQUIRE( soldier->getHitPoints() == 200 );
        REQUIRE( soldier->getHitPointsLimit() == 200 );
        REQUIRE( soldier->getDamage() == 20 );

        Vampire* vampire = new Vampire("Vampire", 200, 40 );

        REQUIRE( vampire->getTitle() == "Vampire" );
        REQUIRE( vampire->getHitPoints() == 200 );
        REQUIRE( vampire->getHitPointsLimit() == 200 );
        REQUIRE( vampire->getDamage() == 40 );
        REQUIRE( vampire->isWerewolf() == false );
        REQUIRE( vampire->isUndead() == true );

        werewolf->turn(vampire);

        REQUIRE( vampire->getTitle() == "Vampire" );
        REQUIRE( vampire->getHitPoints() == 200 );
        REQUIRE( vampire->getHitPointsLimit() == 200 );
        REQUIRE( vampire->getDamage() == 40 );
        REQUIRE( vampire->isWerewolf() == false );
        REQUIRE( vampire->isUndead() == true );
    }
}
