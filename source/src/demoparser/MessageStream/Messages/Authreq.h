/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_AUTHREQ
#define PARSER_MESSAGE_AUTHREQ

class Authreq: public Message
{
  public:
    Authreq(): Message(SV_AUTHREQ)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    char authKey[MAXTRANS];
};

#endif
