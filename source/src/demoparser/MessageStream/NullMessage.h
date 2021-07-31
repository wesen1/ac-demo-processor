/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Message.h"

#ifndef PARSER_NULL_MESSAGE
#define PARSER_NULL_MESSAGE

class NullMessage: public Message
{
  using Message::Message;

  void extractDataFromBuffer(ucharbuf*);
};

#endif
