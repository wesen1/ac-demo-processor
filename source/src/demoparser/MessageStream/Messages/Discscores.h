/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_DISCSCORES
#define PARSER_MESSAGE_DISCSCORES

class Discscores: public Message
{
  public:
    Discscores(): Message(SV_DISCSCORES)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    char playerName[MAXTRANS];
    int numberOfFlags;
    int numberOfFrags;
    int numberOfDeaths;
    int numberOfPoints;
};

#endif
