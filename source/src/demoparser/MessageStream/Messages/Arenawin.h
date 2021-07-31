/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_ARENAWIN
#define PARSER_MESSAGE_ARENAWIN

class Arenawin: public Message
{
  public:
    Arenawin(): Message(SV_ARENAWIN)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int actorClientNumber;
};

#endif
