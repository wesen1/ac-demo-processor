/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_PONG
#define PARSER_MESSAGE_PONG

class Pong: public Message
{
  public:
    Pong(): Message(SV_PONG)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int millis;
};

#endif
