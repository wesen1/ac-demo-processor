/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SERVOPINFO
#define PARSER_MESSAGE_SERVOPINFO

class Servopinfo: public Message
{
  public:
    Servopinfo(): Message(SV_SERVOPINFO)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
    int newRole;
};

#endif
