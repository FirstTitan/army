all: state/MagicState.o state/WerewolfState.o state/BerserkerState.o state/State.o unit/Demon.o unit/Vampire.o unit/Unit.o unit/Rogue.o unit/Soldier.o unit/Werewolf.o unit/Berserker.o ability/PriestAbility.o ability/WarlockAbility.o ability/DefaultAbility.o ability/VampireAbility.o ability/WizardAbility.o ability/WerewolfAbility.o ability/Ability.o ability/NecromancerAbility.o ability/RogueAbility.o ability/HealerAbility.o ability/MagicAbility.o interface/Observer.o interface/Observable.o spellcaster/SpellCaster.o spellcaster/Healer.o spellcaster/Warlock.o spellcaster/Wizard.o spellcaster/Necromancer.o spellcaster/Priest.o spell/Spell.o spell/SpellBook.o spell/FireBall.o spell/Heal.o main.o linking start

state/MagicState.o:
	g++ -c state/MagicState.cpp -o state/MagicState.o
state/WerewolfState.o:
	g++ -c state/WerewolfState.cpp -o state/WerewolfState.o
state/BerserkerState.o:
	g++ -c state/BerserkerState.cpp -o state/BerserkerState.o
state/State.o:
	g++ -c state/State.cpp -o state/State.o
unit/Demon.o:
	g++ -c unit/Demon.cpp -o unit/Demon.o
unit/Vampire.o:
	g++ -c unit/Vampire.cpp -o unit/Vampire.o
unit/Unit.o:
	g++ -c unit/Unit.cpp -o unit/Unit.o
unit/Rogue.o:
	g++ -c unit/Rogue.cpp -o unit/Rogue.o
unit/Soldier.o:
	g++ -c unit/Soldier.cpp -o unit/Soldier.o
unit/Werewolf.o:
	g++ -c unit/Werewolf.cpp -o unit/Werewolf.o
unit/Berserker.o:
	g++ -c unit/Berserker.cpp -o unit/Berserker.o
ability/PriestAbility.o:
	g++ -c ability/PriestAbility.cpp -o ability/PriestAbility.o
ability/WarlockAbility.o:
	g++ -c ability/WarlockAbility.cpp -o ability/WarlockAbility.o
ability/DefaultAbility.o:
	g++ -c ability/DefaultAbility.cpp -o ability/DefaultAbility.o
ability/VampireAbility.o:
	g++ -c ability/VampireAbility.cpp -o ability/VampireAbility.o
ability/WizardAbility.o:
	g++ -c ability/WizardAbility.cpp -o ability/WizardAbility.o
ability/WerewolfAbility.o:
	g++ -c ability/WerewolfAbility.cpp -o ability/WerewolfAbility.o
ability/Ability.o:
	g++ -c ability/Ability.cpp -o ability/Ability.o
ability/Necromancer.o:
	g++ -c ability/NecromancerAbility.cpp -o ability/NecromancerAbility.o
ability/RogueAbility.o:
	g++ -c ability/RogueAbility.cpp -o ability/RogueAbility.o
ability/HealerAbility.o:
	g++ -c ability/HealerAbility.cpp -o ability/HealerAbility.o
ability/MagicAbility.o:
	g++ -c ability/MagicAbility.cpp -o ability/MagicAbility.o
interface/Observer.o:
	g++ -c interface/Observer.cpp -o interface/Observer.o
interface/Observable.o:
	g++ -c interface/Observable.cpp -o interface/Observable.o
spellcaster/SpellCaster.o:
	g++ -c spellcaster/SpellCaster.cpp -o spellcaster/SpellCaster.o
spellcaster/Healer.o:
	g++ -c spellcaster/Healer.cpp -o spellcaster/Healer.o
spellcaster/Warlock.o:
	g++ -c spellcaster/Warlock.cpp -o spellcaster/Warlock.o
spellcaster/Wizard.o:
	g++ -c spellcaster/Wizard.cpp -o spellcaster/Wizard.o
spellcaster/Necromancer.o:
	g++ -c spellcaster/Necromancer.cpp -o spellcaster/Necromancer.o
spellcaster/Priest.o:
	g++ -c spellcaster/Priest.cpp -o spellcaster/Priest.o
spell/Spell.o:
	g++ -c spell/Spell.cpp -o spell/Spell.o
spell/SpellBook.o:
	g++ -c spell/SpellBook.cpp -o spell/SpellBook.o
spell/FireBall.o:
	g++ -c spell/FireBall.cpp -o spell/FireBall.o
spell/Heal.o:
	g++ -c spell/Heal.cpp -o spell/Heal.o
main.o:
	g++ -c main.cpp -o main.o

linking:
	g++ state/MagicState.o state/WerewolfState.o state/BerserkerState.o state/State.o unit/Demon.o unit/Vampire.o unit/Unit.o unit/Rogue.o unit/Soldier.o unit/Werewolf.o unit/Berserker.o ability/PriestAbility.o ability/WarlockAbility.o ability/DefaultAbility.o ability/VampireAbility.o ability/WizardAbility.o ability/WerewolfAbility.o ability/Ability.o ability/NecromancerAbility.o ability/RogueAbility.o ability/HealerAbility.o ability/MagicAbility.o interface/Observer.o interface/Observable.o spellcaster/SpellCaster.o spellcaster/Healer.o spellcaster/Warlock.o spellcaster/Wizard.o spellcaster/Necromancer.o spellcaster/Priest.o spell/Spell.o spell/SpellBook.o spell/FireBall.o spell/Heal.o main.o -o list

start: list
	./list
clean:
	rm state/MagicState.o state/WerewolfState.o state/BerserkerState.o state/State.o unit/Demon.o unit/Vampire.o unit/Unit.o unit/Rogue.o unit/Soldier.o unit/Werewolf.o unit/Berserker.o ability/PriestAbility.o ability/WarlockAbility.o ability/DefaultAbility.o ability/VampireAbility.o ability/WizardAbility.o ability/WerewolfAbility.o ability/Ability.o ability/NecromancerAbility.o ability/RogueAbility.o ability/HealerAbility.o ability/MagicAbility.o interface/Observer.o interface/Observable.o spellcaster/SpellCaster.o spellcaster/Healer.o spellcaster/Warlock.o spellcaster/Wizard.o spellcaster/Necromancer.o spellcaster/Priest.o spell/Spell.o spell/SpellBook.o spell/FireBall.o spell/Heal.o main.o list
