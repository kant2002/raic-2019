#include "Debug.hpp"
#include "model/PlayerMessageGame.hpp"

void Debug::mark(const Unit& unit) {
    this->draw(
        CustomData::Rect(
            Vec2Float(unit.position.x, unit.position.y),
            Vec2Float(unit.size.x, unit.size.y),
            ColorFloat(1, 0, 0, 0.5)));
}
void Debug::mark(const Vec2Double& position) {
    this->draw(
        CustomData::Rect(
            Vec2Float(position.x - 0.05, position.y - 0.05),
            Vec2Float(0.1, 0.1),
            ColorFloat(1, 0, 0, 0.5)));
}

void Debug::mark(const LootBox& unit) {
    this->draw(
        CustomData::Rect(
            Vec2Float(unit.position.x, unit.position.y),
            Vec2Float(unit.size.x, unit.size.y),
            ColorFloat(0, 1, 0, 0.5)));
}

void Debug::drawAim(const Vec2Double& aim, const Unit& unit)
{
    if (unit.weapon == nullptr) {
        return;
    }

    if (unit.weapon->lastAngle == nullptr) {
        return;
    }

    auto dx = unit.position.x - aim.x;
    auto dy = unit.position.y - aim.y;
    this->draw(
        CustomData::Line(
            Vec2Float(unit.position.x, unit.position.y),
            Vec2Float(aim.x, aim.y),
            0.1,
            ColorFloat(0, 1, 0, 0.5)));
}
