#ifndef _DEBUG_HPP_
#define _DEBUG_HPP_

#include "model/CustomData.hpp"
#include "model/Unit.hpp"
#include "model/LootBox.hpp"

class Debug {
public:
    virtual void draw(const CustomData& customData) = 0;
    void mark(const Unit& unit);
    void mark(const Vec2Double& position);
    void mark(const LootBox& lootbox);
    void drawAim(const Vec2Double& aim, const Unit& unit);
};

#endif