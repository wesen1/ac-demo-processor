/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "PacketStream.h"


/**
 * PacketStream constructor.
 *
 * @param PacketParser _packetParser The packet parser to use to parse the next packets
 * @param stream _demoData The demo data stream to extract the next packets from
 */
PacketStream::PacketStream(PacketParser* _packetParser, stream* _demoData)
{
  packetParser = _packetParser;
  demoData = _demoData;
}


// Public Methods

/**
 * Fetches and returns the next packet from the demo data stream.
 *
 * @return Packet The next packet from the demo data stream
 */
Packet* PacketStream::getNextPacket()
{
  return packetParser->parseNextPacketFromStream(demoData);
}
