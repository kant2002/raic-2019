#include "NoOpStrategy.hpp"

UnitAction NoOpStrategy::getAction(
	const Unit& unit,
	const Game& game,
	Debug& debug) {
	UnitAction action;
	action.aim = Vec2Double(0.0, 0.0);
	action.jump = false;
	action.jumpDown = false;
	action.plantMine = false;
	action.reload = false;
	action.shoot = false;
	action.swapWeapon = false;
	action.velocity = 0.0;
	return action;
}
