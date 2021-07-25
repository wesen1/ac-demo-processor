/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_FLAGCNT
#define PARSER_MESSAGE_FLAGCNT

class Flagcnt: public Message
{
  public:
    Flagcnt(): Message(SV_FLAGCNT)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
    int numberOfFlags;
};

#endif
