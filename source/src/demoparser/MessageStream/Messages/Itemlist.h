/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"
#include <vector>

#ifndef PARSER_MESSAGE_ITEMLIST
#define PARSER_MESSAGE_ITEMLIST

class Itemlist: public Message
{
  public:
    Itemlist(): Message(SV_ITEMLIST)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    std::vector<int> itemIds;
};

#endif
