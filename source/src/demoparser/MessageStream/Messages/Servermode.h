/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SERVERMODE
#define PARSER_MESSAGE_SERVERMODE

class Servermode: public Message
{
  public:
    Servermode(): Message(SV_SERVERMODE)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int serverMode;
};

#endif
