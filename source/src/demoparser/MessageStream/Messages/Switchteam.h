/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SWITCHTEAM
#define PARSER_MESSAGE_SWITCHTEAM

class Switchteam: public Message
{
  public:
    Switchteam(): Message(SV_SWITCHTEAM)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int newTeamId;
};

#endif
