/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SERVINFO
#define PARSER_MESSAGE_SERVINFO

class Servinfo: public Message
{
  public:
    Servinfo(): Message(SV_SERVINFO)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
    int protocolVersion;
    int sessionId;
    int isPasswordProtectedServer;
};

#endif
