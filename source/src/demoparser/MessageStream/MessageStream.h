/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "MessageParser.h"
#include "Message.h"
#include "Messages/Client.h"
#include "cube.h"

#ifndef PARSER_MESSAGE_STREAM
#define PARSER_MESSAGE_STREAM

class MessageStream
{
  private:
    MessageParser* messageParser;
    int channel;
    ucharbuf* messageDataBuffer;
    Client* lastClientMessage;

  public:
    MessageStream(MessageParser*, int, ucharbuf*);
    Message* getNextMessage();
};

#endif
