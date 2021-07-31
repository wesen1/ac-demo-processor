/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_HITPUSH
#define PARSER_MESSAGE_HITPUSH

class Hitpush: public Message
{
  public:
    Hitpush(): Message(SV_HITPUSH)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int weaponId;
    int damage;
    vec dir;
};

#endif
