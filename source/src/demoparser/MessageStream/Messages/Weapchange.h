/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_WEAPCHANGE
#define PARSER_MESSAGE_WEAPCHANGE

class Weapchange: public Message
{
  public:
    Weapchange(): Message(SV_WEAPCHANGE)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int newWeaponId;
};

#endif
