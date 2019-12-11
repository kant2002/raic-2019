#include "MyStrategy.hpp"
#include "UnitWorldContext.hpp"

MyStrategy::MyStrategy() {}

UnitAction MyStrategy::getAction(
	const Unit& unit,
	const Game& game,
	Debug& debug) {

	UnitWorldContext context(unit);

	// Firstly we observe world.
	context.findNearestUnit(game.units);
	if (context.nearestEnemy != nullptr) {
		debug.mark(*context.nearestEnemy);
	}

	// Calculate plan of movements/actions
	context.setTargetPosition(game);
	debug.mark(context.targetPos);
	debug.draw(CustomData::Log(
		std::string("Target pos: ") + context.targetPos.toString()));

	UnitAction action;

	// Plan movement
	context.setMovementActions(action, game.level.tiles);

	// Plan attack actions
	context.setAttackActions(action);
	if (context.nearestEnemy) {
		debug.drawAim(context.targetPos, unit);
	}

	return action;
}