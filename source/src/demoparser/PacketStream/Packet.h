/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../MessageStream/MessageStream.h"

#ifndef PACKETSTREAM_PACKET
#define PACKETSTREAM_PACKET

class Packet
{
  private:
    int timestamp;
    int channel;
    MessageStream* messageStream;

  public:
    Packet(int, int, MessageStream*);
    int getTimestamp();
    int getChannel();
    MessageStream* getMessageStream();
};

#endif
