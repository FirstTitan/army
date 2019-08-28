test_priest:
	g++ test_priest.cpp ../spellcaster/Priest.cpp ../spellcaster/SpellCaster.cpp ../unit/Unit.cpp ../state/State.cpp ../state/MagicState.cpp ../spell/Spell.cpp ../spell/Heal.cpp ../spell/FireBall.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../ability/MagicAbility.cpp ../ability/PriestAbility.cpp ../unit/Soldier.cpp ../unit/Vampire.cpp ../ability/VampireAbility.cpp -o start
	./start
test_healer:
	g++ test_healer.cpp ../spellcaster/Healer.cpp ../unit/Unit.cpp ../state/State.cpp ../state/MagicState.cpp ../spell/Spell.cpp ../spell/Heal.cpp ../spell/FireBall.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../ability/MagicAbility.cpp ../ability/HealerAbility.cpp ../spellcaster/SpellCaster.cpp ../unit/Soldier.cpp -o start
	./start
test_wizard:
	g++ test_wizard.cpp ../spellcaster/Wizard.cpp ../unit/Unit.cpp ../state/State.cpp ../state/MagicState.cpp ../spell/Spell.cpp ../spell/Heal.cpp ../spell/FireBall.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../ability/MagicAbility.cpp ../ability/WizardAbility.cpp ../spellcaster/SpellCaster.cpp ../unit/Soldier.cpp -o start
	./start
test_werewolf:
	g++ test_werewolf.cpp ../unit/Werewolf.cpp ../unit/Unit.cpp ../state/State.cpp ../state/WerewolfState.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../unit/Soldier.cpp -o start
	./start
test_vampire:
	g++ test_vampire.cpp ../unit/Vampire.cpp ../unit/Unit.cpp ../state/State.cpp ../ability/Ability.cpp ../ability/VampireAbility.cpp ../unit/Soldier.cpp ../ability/DefaultAbility.cpp -o start
	./start
test_berserker:
	g++ test_berserker.cpp ../unit/Berserker.cpp ../unit/Unit.cpp ../state/State.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../state/BerserkerState.cpp -o start
	./start
test_rogue:
	g++ test_rogue.cpp ../unit/Rogue.cpp ../unit/Unit.cpp ../state/State.cpp ../unit/Soldier.cpp ../ability/RogueAbility.cpp ../ability/DefaultAbility.cpp ../ability/Ability.cpp -o start
	./start
test_soldier:
	g++ test_soldier.cpp ../unit/Soldier.cpp ../unit/Unit.cpp ../ability/Ability.cpp ../ability/DefaultAbility.cpp ../state/State.cpp -o start
	./start
test_state:
	g++ test_state.cpp ../state/State.cpp -o start
	./start
test_magicstate:
	g++ test_magicstate.cpp ../state/MagicState.cpp -o start
	./start
clean:
	rm start
