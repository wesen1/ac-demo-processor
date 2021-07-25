/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../MessageStream/MessageParser.h"
#include "Packet.h"
#include "cube.h"

#ifndef PACKET_PARSER
#define PACKET_PARSER

class PacketParser
{
  private:
    MessageParser* messageParser;

  public:
    PacketParser(MessageParser*);
    Packet* parseNextPacketFromStream(stream*);
};

#endif
