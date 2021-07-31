/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_TEXTME
#define PARSER_MESSAGE_TEXTME

class Textme: public Message
{
  public:
    using Message::Message;

    void extractDataFromBuffer(ucharbuf*);


    char message[MAXTRANS];
};

#endif
