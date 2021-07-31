/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_WELCOME
#define PARSER_MESSAGE_WELCOME

class Welcome: public Message
{
  public:
    Welcome(): Message(SV_WELCOME)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int joining;
};

#endif
