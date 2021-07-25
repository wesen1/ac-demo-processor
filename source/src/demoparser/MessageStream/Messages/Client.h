/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_CLIENT
#define PARSER_MESSAGE_CLIENT

class Client: public Message
{
  public:
    Client(): Message(SV_CLIENT)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
    ucharbuf clientMessagesBuffer;
};

#endif
