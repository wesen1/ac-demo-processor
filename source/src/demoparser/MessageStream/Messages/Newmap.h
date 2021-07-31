/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_NEWMAP
#define PARSER_MESSAGE_NEWMAP

class Newmap: public Message
{
  public:
    Newmap(): Message(SV_NEWMAP)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int newMapSize;
};

#endif
