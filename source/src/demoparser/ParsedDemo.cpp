/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "ParsedDemo.h"


/**
 * ParsedDemo constructor.
 *
 * @param demoheader _demoHeader The demo header
 * @param PacketStream _packetStream The stream of packets that are contained in the demo
 */
ParsedDemo::ParsedDemo(demoheader* _demoHeader, PacketStream* _packetStream)
{
  demoHeader = _demoHeader;
  packetStream = _packetStream;
}


// Getters and Setters

/**
 * Returns the demo header.
 *
 * @return demoheader The demo header
 */
struct demoheader* ParsedDemo::getDemoHeader()
{
  return demoHeader;
}

/**
 * Returns the stream of packets that are contained in the demo.
 *
 * @return PacketStream The packet stream
 */
PacketStream* ParsedDemo::getPacketStream()
{
  return packetStream;
}
