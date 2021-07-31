/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_ITEMSPAWN
#define PARSER_MESSAGE_ITEMSPAWN

class Itemspawn: public Message
{
  public:
    Itemspawn(): Message(SV_ITEMSPAWN)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int itemId;
};

#endif
