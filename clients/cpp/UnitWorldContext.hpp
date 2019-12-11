#ifndef _UNIT_WORLD_CONTEXT_HPP_
#define __UNIT_WORLD_CONTEXT_HPP_

#include <vector>
#include "model/Unit.hpp"
#include "model/Game.hpp"
#include "model/UnitAction.hpp"

class UnitWorldContext
{
	const Unit& self;
public:
	const Unit* nearestEnemy;
	bool jump;
	Vec2Double targetPos;

	UnitWorldContext(const Unit& targetUnit);
	void findNearestUnit(const std::vector<Unit>& units);
	void setTargetPosition(const Game& game);
	void setMovementActions(UnitAction& action, const std::vector<std::vector<Tile>>& tiles);
	void setAttackActions(UnitAction& action);
};

#endif
