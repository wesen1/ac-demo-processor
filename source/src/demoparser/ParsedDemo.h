/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "PacketStream/PacketStream.h"
#include "cube.h"

#ifndef PARSED_DEMO
#define PARSED_DEMO

class ParsedDemo
{
  private:
    demoheader* demoHeader;
    PacketStream* packetStream;

  public:
    ParsedDemo(demoheader*, PacketStream*);
    struct demoheader* getDemoHeader();
    PacketStream* getPacketStream();
};

#endif
