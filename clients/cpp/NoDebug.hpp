#ifndef _NO_DEBUG_HPP_
#define _NO_DEBUG_HPP_

#include "Debug.hpp"

class NoDebug : public Debug {
public:
    void draw(const CustomData& customData);
};

#endif