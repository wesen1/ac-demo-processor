/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Message.h"
#include "cube.h"

#ifndef MESSAGE_PARSER
#define MESSAGE_PARSER

class MessageParser
{
  private:
    int demoprotocol;
    Message* parseNextMessageFromPositionMessagesBuffer(ucharbuf*);
    Message* parseNextMessageFromGeneralMessagesBuffer(ucharbuf*);
    Message* parseNextMessageFromFileTransmissionMessagesBuffer(ucharbuf*);
    Message* createMessageForMessageType(int);

  public:
    MessageParser(int);
    Message* parseNextMessageFromBuffer(int, ucharbuf*);
};

#endif
