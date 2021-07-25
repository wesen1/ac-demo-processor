/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SWITCHSKIN
#define PARSER_MESSAGE_SWITCHSKIN

class Switchskin: public Message
{
  public:
    Switchskin(): Message(SV_SWITCHSKIN)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int skins[2];
};

#endif
