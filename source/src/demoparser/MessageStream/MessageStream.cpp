/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "MessageStream.h"


/**
 * MessageStream constructor.
 *
 * @param MessageParser _messageParser The MessageParser to use to extract the next messages
 * @param int _channel The channel of the messages
 * @param ucharbuf _messageDataBuffer The message data buffer to extract the next messages from
 */
MessageStream::MessageStream(MessageParser* _messageParser, int _channel, ucharbuf* _messageDataBuffer)
{
  messageParser = _messageParser;
  channel = _channel;
  messageDataBuffer = _messageDataBuffer;
  lastClientMessage = NULL;
}


// Getters and Setters

/**
 * Returns the message data buffer from which the messages are extracted.
 *
 * @return ucharbuf The message data buffer
 */
ucharbuf* MessageStream::getMessageDataBuffer()
{
  return messageDataBuffer;
}


// Public Methods

/**
 * Extracts and returns the next message from the message data buffer.
 *
 * @return Message The next message from the message data buffer
 */
Message* MessageStream::getNextMessage()
{
  Message* nextMessage;

  // Check if there are nested messages from a SV_CLIENT message
  if (lastClientMessage)
  {
    if (lastClientMessage->clientMessagesBuffer.remaining() > 0)
    {
      nextMessage = messageParser->parseNextMessageFromBuffer(1, &lastClientMessage->clientMessagesBuffer);
      if (lastClientMessage)
      {
        lastClientMessage->addChildMessage(nextMessage);
      }
      if (nextMessage) return nextMessage;
    }

    lastClientMessage = NULL;
  }

  // Check if there are more messages in the message data buffer
  if (messageDataBuffer->remaining() <= 0)
  {
    return NULL;
  }

  nextMessage = messageParser->parseNextMessageFromBuffer(channel, messageDataBuffer);
  if (nextMessage && nextMessage->getType() == SV_CLIENT)
  {
    lastClientMessage = static_cast<Client*>(nextMessage);
  }

  return nextMessage;
}
