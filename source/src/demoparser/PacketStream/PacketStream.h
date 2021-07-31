/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Packet.h"
#include "PacketParser.h"
#include "cube.h"

#ifndef PACKET_STREAM
#define PACKET_STREAM

class PacketStream
{
  private:
    PacketParser* packetParser;
    stream* demoData;

  public:
    PacketStream(PacketParser*, stream*);
    Packet* getNextPacket();
};

#endif
