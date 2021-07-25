/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_FORCEDEATH
#define PARSER_MESSAGE_FORCEDEATH

class Forcedeath: public Message
{
  public:
    Forcedeath(): Message(SV_FORCEDEATH)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
};

#endif
