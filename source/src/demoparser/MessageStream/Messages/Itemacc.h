/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_ITEMACC
#define PARSER_MESSAGE_ITEMACC

class Itemacc: public Message
{
  public:
    Itemacc(): Message(SV_ITEMACC)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int itemId;
    int clientNumber;
};

#endif
