/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_RELOAD
#define PARSER_MESSAGE_RELOAD

class Reload: public Message
{
  public:
    Reload(): Message(SV_RELOAD)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
    int weaponId;
};

#endif
