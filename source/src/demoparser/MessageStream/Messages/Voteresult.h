/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_VOTERESULT
#define PARSER_MESSAGE_VOTERESULT

class Voteresult: public Message
{
  public:
    Voteresult(): Message(SV_VOTERESULT)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int voteResult;
};

#endif
