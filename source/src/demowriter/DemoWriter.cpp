/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "DemoWriter.h"
#include <algorithm>


/**
 * DemoWriter constructor.
 *
 * @param std::vector<std::string> _messageTypesToRemove The message types that should be filtered out while writing demos
 */
DemoWriter::DemoWriter(std::vector<std::string> _messageTypesToRemove)
{
  messageTypesToRemove = _messageTypesToRemove;
  currentClientMessage = NULL;
}


// Public Methods

/**
 * Writes a given ParsedDemo to a given output stream.
 *
 * @param stream _outputFile The output stream to write to
 * @param ParsedDemo _parsedDemo The ParsedDemo to write
 */
void DemoWriter::writeDemo(stream* _outputFile, ParsedDemo* _parsedDemo)
{
  writeDemoHeader(_outputFile, _parsedDemo->getDemoHeader());

  Packet* nextPacket;
  do
  {
    nextPacket = _parsedDemo->getPacketStream()->getNextPacket();
    if (nextPacket)
    {
      uchar* data = new uchar[MAXTRANS];
      ucharbuf* newPacketPayload = new ucharbuf(data, MAXTRANS);
      generatePacketPayload(nextPacket, newPacketPayload);
      writePacket(_outputFile, nextPacket, newPacketPayload);
    }
  }
  while (nextPacket);
}


// Private Methods

/**
 * Writes a given demoheader to a given output stream.
 *
 * @param stream _outputFile The output stream to write to
 * @param demoheader _demoHeader The demoheader to write
 */
void DemoWriter::writeDemoHeader(stream* _outputFile, demoheader* _demoHeader)
{
  lilswap(&_demoHeader->version, 1);
  lilswap(&_demoHeader->protocol, 1);
  _outputFile->write(_demoHeader, sizeof(demoheader));
}

/**
 * Writes a packet with a given payload buffer to a given output stream.
 *
 * @param stream _outputFile The output stream to write to
 * @param Packet _packet The packet to write
 * @param ucharbuf _packetPayloadBuffer The packet payload buffer to write
 */
void DemoWriter::writePacket(stream* _outputFile, Packet* _packet, ucharbuf* _packetPayloadBuffer)
{
  if (_packetPayloadBuffer->length() > 0)
  {
    // Write packet header
    int packetHeader[3] = {
      _packet->getTimestamp(),
      _packet->getChannel(),
      _packetPayloadBuffer->length()
    };
    lilswap(packetHeader, 3);
    _outputFile->write(packetHeader, sizeof(packetHeader));

    // Write packet payload
    _outputFile->write(_packetPayloadBuffer->buf, _packetPayloadBuffer->length());
  }
}

/**
 * Generates a packet payload for a given packet.
 *
 * @param Packet _packet The packet to generate a payload for
 * @param ucharbuf _packetPayloadBuffer The packet payload buffer to write the generated payload to
 */
void DemoWriter::generatePacketPayload(Packet* _packet, ucharbuf* _packetPayloadBuffer)
{
  if (_packet->getChannel() == 1)
  {
    generatePacketPayloadFromMessageStream(_packet->getMessageStream(), _packetPayloadBuffer);
  }
  else
  { // Channel type that is not parsed by the MessageParser, simply restore the original packet data
    restoreOriginalPacketPayload(_packet, _packetPayloadBuffer);
  }
}

/**
 * Generates a packet payload from a given MessageStream.
 *
 * @param MessageStream _messageStream The MessageStream to generate a payload from
 * @param ucharbuf _packetPayloadBuffer The packet payload buffer to write the generated payload to
 */
void DemoWriter::generatePacketPayloadFromMessageStream(MessageStream* _messageStream, ucharbuf* _packetPayloadBuffer)
{
  currentClientMessage = NULL;

  Message* nextMessage;
  do
  {
    nextMessage = _messageStream->getNextMessage();
    if (nextMessage)
    {
      if (currentClientMessage &&
          nextMessage->getParentClientMessage() != currentClientMessage)
      {
        addCurrentClientMessage(_packetPayloadBuffer);
      }

      if (shouldMessageBeRemoved(nextMessage))
      {
        clientlogf("Removing message: %s", nextMessage->getTypeName());
        removeMessage(nextMessage);
      }
      else
      {
        //clientlogf("Adding message: %s", nextMessage->getTypeName());
        addMessage(nextMessage, _packetPayloadBuffer);
      }
    }
  } while (nextMessage);

  if (currentClientMessage)
  {
    addCurrentClientMessage(_packetPayloadBuffer);
  }
}

/**
 * Returns whether a given Message should be removed from a packet.
 *
 * @param Message _message The Message to check
 *
 * @return bool True if the given Message should be removed from a packet, false otherwise
 */
bool DemoWriter::shouldMessageBeRemoved(Message* _message)
{
  std::string messageType(_message->getTypeName());
  return (std::find(messageTypesToRemove.begin(), messageTypesToRemove.end(), messageType) != messageTypesToRemove.end());
}

/**
 * Removes a given Message from the currently written packet.
 *
 * @param Message _message The Message to remove
 */
void DemoWriter::removeMessage(Message* _message)
{
  if (_message->getParentClientMessage())
  {
    Client* parentClientMessage = static_cast<Client*>(_message->getParentClientMessage());
    parentClientMessage->removeChildMessage(_message);
  }
}

/**
 * Adds a given Message to the currently written packet.
 *
 * @param Message _message The Message to add
 * @param ucharbuf _packetPayloadBuffer The packet payload buffer to write the Message to
 */
void DemoWriter::addMessage(Message* _message, ucharbuf* _packetPayloadBuffer)
{
  if (_message->getParentClientMessage())
  {
    currentClientMessage = static_cast<Client*>(_message->getParentClientMessage());
  }
  else if (_message->getType() != SV_CLIENT)
  {
    _message->writeToBuffer(_packetPayloadBuffer);
  }
}

/**
 * Adds the current Client message to the currently written packet.
 *
 * @param ucharbuf _packetPayloadBuffer The packet payload buffer to write the current Client Message to
 */
void DemoWriter::addCurrentClientMessage(ucharbuf* _packetPayloadBuffer)
{
  currentClientMessage->writeToBuffer(_packetPayloadBuffer);
  currentClientMessage = NULL;
}

/**
 * Writes the original payload of a given packet to a given data buffer.
 *
 * @param Packet _packet The packet whose original payload to write
 * @param ucharbuf _packetPayloadBuffer The buffer to write the packet payload to
 */
void DemoWriter::restoreOriginalPacketPayload(Packet* _packet, ucharbuf* _packetPayloadBuffer)
{
  ucharbuf* messageDataBuffer = _packet->getMessageStream()->getMessageDataBuffer();
  messageDataBuffer->len = 0;

  _packetPayloadBuffer->put(messageDataBuffer->buf, messageDataBuffer->remaining());
}
