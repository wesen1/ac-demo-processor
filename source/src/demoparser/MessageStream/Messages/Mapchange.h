/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_MAPCHANGE
#define PARSER_MESSAGE_MAPCHANGE

class Mapchange: public Message
{
  public:
    Mapchange(): Message(SV_MAPCHANGE)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    char mapName[MAXTRANS];
    int gameMode;
    int downloadable;
    int revision;
};

#endif
