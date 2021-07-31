/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SPAWNDENY
#define PARSER_MESSAGE_SPAWNDENY

class Spawndeny: public Message
{
  public:
    Spawndeny(): Message(SV_SPAWNDENY)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int spawnpermission;
};

#endif
