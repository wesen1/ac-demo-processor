/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_AUTHCHAL
#define PARSER_MESSAGE_AUTHCHAL

class Authchal: public Message
{
  public:
    Authchal(): Message(SV_AUTHCHAL)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    char authKey[MAXTRANS];
    uint id;
    char challenge[MAXTRANS];
};

#endif
