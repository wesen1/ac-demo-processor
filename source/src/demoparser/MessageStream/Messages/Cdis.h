/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_CDIS
#define PARSER_MESSAGE_CDIS

class Cdis: public Message
{
  public:
    Cdis(): Message(SV_CDIS)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
};

#endif
