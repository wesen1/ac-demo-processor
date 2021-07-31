/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_FLAGMSG
#define PARSER_MESSAGE_FLAGMSG

class Flagmsg: public Message
{
  public:
    Flagmsg(): Message(SV_FLAGMSG)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int flagId;
    int flagMessageId;
    int actorClientNumber;
    int flagtime;
};

#endif
