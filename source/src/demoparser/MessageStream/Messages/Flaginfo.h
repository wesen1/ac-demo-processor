/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_FLAGINFO
#define PARSER_MESSAGE_FLAGINFO

class Flaginfo: public Message
{
  public:
    Flaginfo(): Message(SV_FLAGINFO)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int flagId;
    int flagState;
    int actorClientNumber;
    float x;
    float y;
    float z;
};

#endif
