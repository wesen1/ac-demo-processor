/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Packet.h"


/**
 * Packet constructor.
 *
 * @param int _timestamp The timestamp
 * @param int _channel The channel number
 * @param MessageStream _messageStream The stream of messages that are contained in the packet
 */
Packet::Packet(int _timestamp, int _channel, MessageStream* _messageStream)
{
  timestamp = _timestamp;
  channel = _channel;
  messageStream = _messageStream;
}


// Getters and Setters

/**
 * Returns the packet timestamp.
 *
 * @return int The timestamp
 */
int Packet::getTimestamp()
{
  return timestamp;
}

/**
 * Returns the channel number.
 *
 * @return int The channel number
 */
int Packet::getChannel()
{
  return channel;
}

/**
 * Returns the stream of messages that are contained in the packet.
 *
 * @return MessageStream The message stream
 */
MessageStream* Packet::getMessageStream()
{
  return messageStream;
}
