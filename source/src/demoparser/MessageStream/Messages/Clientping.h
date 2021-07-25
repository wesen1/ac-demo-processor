/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_CLIENTPING
#define PARSER_MESSAGE_CLIENTPING

class Clientping: public Message
{
  public:
    Clientping(): Message(SV_CLIENTPING)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int ping;
};

#endif
