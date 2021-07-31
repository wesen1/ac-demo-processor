/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SWITCHNAME
#define PARSER_MESSAGE_SWITCHNAME

class Switchname: public Message
{
  public:
    Switchname(): Message(SV_SWITCHNAME)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    char newName[MAXTRANS];
};

#endif
