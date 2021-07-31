/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"
#include <vector>

#ifndef PARSER_MESSAGE_SENDDEMOLIST
#define PARSER_MESSAGE_SENDDEMOLIST

class Senddemolist: public Message
{
  public:
    Senddemolist(): Message(SV_SENDDEMOLIST)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    std::vector<char*> demoNames;
};

#endif
