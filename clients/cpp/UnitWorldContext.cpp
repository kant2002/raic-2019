#include "UnitWorldContext.hpp"

using std::vector;

double distanceSqr(Vec2Double a, Vec2Double b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

const Unit* getNearestUnit(const Unit& unit, const vector<Unit>& units) {
	const Unit* nearestEnemy = nullptr;
	for (const Unit& other : units) {
		if (other.playerId != unit.playerId) {
			if (nearestEnemy == nullptr ||
				distanceSqr(unit.position, other.position) <
				distanceSqr(unit.position, nearestEnemy->position)) {
				nearestEnemy = &other;
			}
		}
	}

	return nearestEnemy;
}

template <typename TItem>
const LootBox* getNearestLootbox(const Unit& unit, const vector<LootBox>& lootBoxes) {
	const LootBox* nearestWeapon = nullptr;
	for (const LootBox& lootBox : lootBoxes) {
		if (std::dynamic_pointer_cast<TItem>(lootBox.item)) {
			if (nearestWeapon == nullptr ||
				distanceSqr(unit.position, lootBox.position) <
				distanceSqr(unit.position, nearestWeapon->position)) {
				nearestWeapon = &lootBox;
			}
		}
	}

	return nearestWeapon;
}

Vec2Double getAim(const Unit& unit, const Unit& enemy)
{
	return Vec2Double(
		enemy.position.x - unit.position.x,
		enemy.position.y - unit.position.y);
}

UnitWorldContext::UnitWorldContext(const Unit& targetUnit)
	: self(targetUnit), nearestEnemy(nullptr), jump(false), targetPos(0, 0)
{
}

void UnitWorldContext::findNearestUnit(const vector<Unit>& units) {
	nearestEnemy = getNearestUnit(self, units);
}

void UnitWorldContext::setTargetPosition(const Game& game) {
	targetPos = self.position;
	auto hasWeapon = self.weapon != nullptr;
	if (!hasWeapon) {
		const LootBox* nearestWeapon = getNearestLootbox<Item::Weapon>(self, game.lootBoxes);
		if (nearestWeapon != nullptr) {
			targetPos = nearestWeapon->position;
		}
	}
	else if (nearestEnemy != nullptr) {
		targetPos = nearestEnemy->position;
	}
}

void UnitWorldContext::setMovementActions(UnitAction& action, const vector<vector<Tile>>& tiles)
{
	bool jump = targetPos.y > self.position.y;
	if (targetPos.x > self.position.x&&
		tiles[size_t(self.position.x + 1)][size_t(self.position.y)] ==
		Tile::WALL) {
		jump = true;
	}

	if (targetPos.x < self.position.x &&
		tiles[size_t(self.position.x - 1)][size_t(self.position.y)] ==
		Tile::WALL) {
		jump = true;
	}

	// Movement actions
	action.velocity = targetPos.x - self.position.x;
	action.jump = jump;
	action.jumpDown = !action.jump;
}

void UnitWorldContext::setAttackActions(UnitAction& action) {
	Vec2Double aim = Vec2Double(0, 0);
	if (nearestEnemy != nullptr) {
		aim = getAim(self, *nearestEnemy);
		action.shoot = true;
	}

	action.aim = aim;
	action.reload = false;
	action.swapWeapon = false;
	action.plantMine = false;
}
