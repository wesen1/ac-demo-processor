/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_INITCLIENT
#define PARSER_MESSAGE_INITCLIENT

class Initclient: public Message
{
  public:
    Initclient(): Message(SV_INITCLIENT)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
    char name[MAXTRANS];
    int skins[2];
    int teamId;
    int address;
};

#endif
