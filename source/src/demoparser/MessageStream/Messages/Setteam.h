/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SETTEAM
#define PARSER_MESSAGE_SETTEAM

class Setteam: public Message
{
  public:
    Setteam(): Message(SV_SETTEAM)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
    int newTeamId;
};

#endif
