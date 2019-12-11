#ifndef _DEBUG_HPP_
#define _DEBUG_HPP_

#include "Stream.hpp"
#include "model/CustomData.hpp"
#include "model/Unit.hpp"
#include "model/LootBox.hpp"
#include <memory>

class Debug {
public:
    Debug(const std::shared_ptr<OutputStream>& outputStream);
    void draw(const CustomData& customData);
    void mark(const Unit& unit);
    void mark(const Vec2Double& position);
    void mark(const LootBox& lootbox);
    void drawAim(const Vec2Double& aim, const Unit& unit);
private:
    std::shared_ptr<OutputStream> outputStream;
};

#endif