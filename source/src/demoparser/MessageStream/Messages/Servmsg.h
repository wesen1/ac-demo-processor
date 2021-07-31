/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SERVMSG
#define PARSER_MESSAGE_SERVMSG

class Servmsg: public Message
{
  public:
    Servmsg(): Message(SV_SERVMSG)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    char message[MAXTRANS];
};

#endif
