#ifndef _NO_OP_STRATEGY_HPP_
#define _NO_OP_STRATEGY_HPP_

#include "Strategy.hpp"

class NoOpStrategy : public Strategy {
public:
    NoOpStrategy() = default;
    UnitAction getAction(const Unit& unit, const Game& game, Debug& debug) override;
};

#endif