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
