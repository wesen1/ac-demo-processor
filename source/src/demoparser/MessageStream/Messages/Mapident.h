/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_MAPIDENT
#define PARSER_MESSAGE_MAPIDENT

class Mapident: public Message
{
  public:
    Mapident(): Message(SV_MAPIDENT)
    {
    }

    void extractDataFromBuffer(ucharbuf*);
};

#endif
