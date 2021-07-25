/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_TEAMDENY
#define PARSER_MESSAGE_TEAMDENY

class Teamdeny: public Message
{
  public:
    Teamdeny(): Message(SV_TEAMDENY)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int teamId;
};

#endif
