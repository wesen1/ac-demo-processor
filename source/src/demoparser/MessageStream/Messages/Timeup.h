/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_TIMEUP
#define PARSER_MESSAGE_TIMEUP

class Timeup: public Message
{
  public:
    Timeup(): Message(SV_TIMEUP)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int currentGameMillis;
    int currentGameLimit;
};

#endif
