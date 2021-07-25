/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_GAMEMODE
#define PARSER_MESSAGE_GAMEMODE

class Gamemode: public Message
{
  public:
    Gamemode(): Message(SV_GAMEMODE)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int nextmode;
};

#endif
