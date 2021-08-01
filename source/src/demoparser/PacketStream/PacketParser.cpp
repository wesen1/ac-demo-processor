/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "PacketParser.h"
#include "../MessageStream/MessageStream.h"


/**
 * PacketParser constructor.
 *
 * @param MessageParser _messageParser The MessageParser to create new MessageStream's with
 */
PacketParser::PacketParser(MessageParser* _messageParser)
{
  messageParser = _messageParser;
}


// Public methods

/**
 * Extracts and returns the next packet from a given stream.
 *
 * @param stream _demoData The stream to extract the next packet from
 *
 * @return Packet The next extracted packet from the given stream
 */
Packet* PacketParser::parseNextPacketFromStream(stream* _demoData)
{
  int timestamp, channel, payloadLength;
  int numberOfReadBytes;

  numberOfReadBytes = _demoData->read(&timestamp, sizeof(timestamp));
  if (numberOfReadBytes != sizeof(timestamp))
  { // No next packet timestamp found in demo data
    return NULL;
  }

  numberOfReadBytes = _demoData->read(&channel, sizeof(channel));
  if (numberOfReadBytes != sizeof(channel))
  { // No next channel number found in demo data
    return NULL;
  }

  numberOfReadBytes = _demoData->read(&payloadLength, sizeof(payloadLength));
  if (numberOfReadBytes != sizeof(payloadLength))
  { // No next payload length found in demo data
    return NULL;
  }


  lilswap(&timestamp, 1);
  lilswap(&channel, 1);
  lilswap(&payloadLength, 1);

  unsigned char* payload = new unsigned char[payloadLength];
  numberOfReadBytes = _demoData->read(payload, payloadLength);
  if (numberOfReadBytes != payloadLength)
  { // No complete next payload found
    return NULL;
  }

  return new Packet(
    timestamp,
    channel,
    new MessageStream(
      messageParser,
      channel,
      new ucharbuf(payload, payloadLength)
    )
  );
}
