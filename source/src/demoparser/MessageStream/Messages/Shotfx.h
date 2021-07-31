/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SHOTFX
#define PARSER_MESSAGE_SHOTFX

class Shotfx: public Message
{
  public:
    Shotfx(): Message(SV_SHOTFX)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int senderClientNumber;
    int weaponId;
    vec to;
};

#endif
