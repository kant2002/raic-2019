#ifndef _MY_STRATEGY_HPP_
#define _MY_STRATEGY_HPP_

#include "Strategy.hpp"

class MyStrategy: public Strategy {
public:
  MyStrategy();
  UnitAction getAction(const Unit &unit, const Game &game, Debug &debug) override;
};

#endif