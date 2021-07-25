/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_HUDEXTRAS
#define PARSER_MESSAGE_HUDEXTRAS

class Hudextras: public Message
{
  public:
    Hudextras(): Message(SV_HUDEXTRAS)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    char value;
};

#endif
