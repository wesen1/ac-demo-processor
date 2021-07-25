/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_CALLVOTESUC
#define PARSER_MESSAGE_CALLVOTESUC

class Callvotesuc: public Message
{
  public:
    Callvotesuc(): Message(SV_CALLVOTESUC)
    {
    }

    void extractDataFromBuffer(ucharbuf*);
};

#endif
