/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_VOTE
#define PARSER_MESSAGE_VOTE

class Vote: public Message
{
  public:
    Vote(): Message(SV_VOTE)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int vote;
};

#endif
