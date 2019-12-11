#ifndef _STRATEGY_HPP_
#define _STRATEGY_HPP_

#include "Debug.hpp"
#include "model/Game.hpp"
#include "model/Unit.hpp"
#include "model/UnitAction.hpp"

class Strategy {
public:
    virtual UnitAction getAction(const Unit& unit, const Game& game, Debug& debug) = 0;
};

#endif
