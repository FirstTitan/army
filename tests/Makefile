all: test_warlock test_necromancer test_priest test_healer test_wizard test_werewolf test_vampire test_berserker test_rogue test_soldier test_state test_magicstate
test_warlock:
	g++ ../spell/SpellBook.cpp ../interface/Observable.cpp ../interface/Observer.cpp test_warlock.cpp ../spellcaster/Warlock.cpp ../spellcaster/SpellCaster.cpp ../unit/Unit.cpp ../unit/Demon.cpp ../unit/Soldier.cpp ../state/State.cpp ../state/MagicState.cpp ../spell/Spell.cpp ../spell/Heal.cpp ../spell/FireBall.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../ability/MagicAbility.cpp ../ability/WarlockAbility.cpp -o start
	./start
test_necromancer:
	g++ ../spell/SpellBook.cpp ../interface/Observable.cpp ../interface/Observer.cpp test_necromancer.cpp ../spellcaster/Necromancer.cpp ../spellcaster/SpellCaster.cpp ../unit/Unit.cpp ../state/State.cpp ../state/MagicState.cpp ../spell/Spell.cpp ../spell/Heal.cpp ../spell/FireBall.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../ability/MagicAbility.cpp ../ability/NecromancerAbility.cpp ../unit/Soldier.cpp -o start
	./start
test_priest:
	g++ ../spell/SpellBook.cpp ../interface/Observable.cpp test_priest.cpp ../spellcaster/Priest.cpp ../spellcaster/SpellCaster.cpp ../unit/Unit.cpp ../state/State.cpp ../state/MagicState.cpp ../spell/Spell.cpp ../spell/Heal.cpp ../spell/FireBall.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../ability/MagicAbility.cpp ../ability/PriestAbility.cpp ../unit/Soldier.cpp ../unit/Vampire.cpp ../ability/VampireAbility.cpp -o start
	./start
test_healer:
	g++ ../spell/SpellBook.cpp ../interface/Observable.cpp test_healer.cpp ../spellcaster/Healer.cpp ../unit/Unit.cpp ../state/State.cpp ../state/MagicState.cpp ../spell/Spell.cpp ../spell/Heal.cpp ../spell/FireBall.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../ability/MagicAbility.cpp ../ability/HealerAbility.cpp ../spellcaster/SpellCaster.cpp ../unit/Soldier.cpp -o start
	./start
test_wizard:
	g++ ../spell/SpellBook.cpp ../interface/Observable.cpp test_wizard.cpp ../spellcaster/Wizard.cpp ../unit/Unit.cpp ../state/State.cpp ../state/MagicState.cpp ../spell/Spell.cpp ../spell/Heal.cpp ../spell/FireBall.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../ability/MagicAbility.cpp ../ability/WizardAbility.cpp ../spellcaster/SpellCaster.cpp ../unit/Soldier.cpp -o start
	./start
test_werewolf:
	g++ ../ability/WerewolfAbility.cpp ../ability/MagicAbility.cpp ../ability/NecromancerAbility.cpp ../spellcaster/SpellCaster.cpp ../spellcaster/Necromancer.cpp ../interface/Observer.cpp ../spell/SpellBook.cpp ../spell/Spell.cpp ../spell/FireBall.cpp ../spell/Heal.cpp ../state/MagicState.cpp ../interface/Observable.cpp test_werewolf.cpp ../unit/Werewolf.cpp ../unit/Unit.cpp ../state/State.cpp ../state/WerewolfState.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../unit/Soldier.cpp ../unit/Vampire.cpp ../ability/VampireAbility.cpp -o start
	./start
test_vampire:
	g++ ../unit/Werewolf.cpp ../ability/WerewolfAbility.cpp ../state/WerewolfState.cpp ../interface/Observable.cpp test_vampire.cpp ../unit/Vampire.cpp ../unit/Unit.cpp ../state/State.cpp ../ability/Ability.cpp ../ability/VampireAbility.cpp ../unit/Soldier.cpp ../ability/DefaultAbility.cpp -o start
	./start
test_berserker:
	g++ ../interface/Observable.cpp test_berserker.cpp ../unit/Berserker.cpp ../unit/Unit.cpp ../state/State.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../state/BerserkerState.cpp -o start
	./start
test_rogue:
	g++ ../interface/Observable.cpp test_rogue.cpp ../unit/Rogue.cpp ../unit/Unit.cpp ../state/State.cpp ../unit/Soldier.cpp ../ability/RogueAbility.cpp ../ability/DefaultAbility.cpp ../ability/Ability.cpp -o start
	./start
test_soldier:
	g++ ../interface/Observable.cpp test_soldier.cpp ../unit/Soldier.cpp ../unit/Unit.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../state/State.cpp -o start
	./start
test_state:
	g++ test_state.cpp ../state/State.cpp -o start
	./start
test_magicstate:
	g++ test_magicstate.cpp ../state/MagicState.cpp -o start
	./start
clean:
	rm start
