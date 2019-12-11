#include "StreamDebug.hpp"
#include "model/PlayerMessageGame.hpp"

StreamDebug::StreamDebug(const std::shared_ptr<OutputStream>& outputStream)
    : outputStream(outputStream) {}

void StreamDebug::draw(const CustomData& customData) {
    outputStream->write(PlayerMessageGame::CustomDataMessage::TAG);
    customData.writeTo(*outputStream);
    outputStream->flush();
}
