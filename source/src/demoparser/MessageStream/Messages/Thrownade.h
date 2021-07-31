/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_THROWNADE
#define PARSER_MESSAGE_THROWNADE

class Thrownade: public Message
{
  public:
    Thrownade(): Message(SV_THROWNADE)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    vec from, to;
    int nademillis;
};

#endif
