/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_CALLVOTEERR
#define PARSER_MESSAGE_CALLVOTEERR

class Callvoteerr: public Message
{
  public:
    Callvoteerr(): Message(SV_CALLVOTEERR)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int errorNumber;
};

#endif
