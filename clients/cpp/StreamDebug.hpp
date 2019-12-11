#ifndef _STREAM_DEBUG_HPP_
#define _STREAM_DEBUG_HPP_

#include "Stream.hpp"
#include "Debug.hpp"
#include <memory>

class StreamDebug: public Debug {
public:
    StreamDebug(const std::shared_ptr<OutputStream>& outputStream);
    void draw(const CustomData& customData) override;
private:
    std::shared_ptr<OutputStream> outputStream;
};

#endif