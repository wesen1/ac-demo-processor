/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"
#include <vector>

#ifndef PARSER_MESSAGE_IPLIST
#define PARSER_MESSAGE_IPLIST

class Iplist: public Message
{
  public:
    Iplist(): Message(SV_IPLIST)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    std::vector<int> clientNumbers;
    std::vector<int> ips;
};

#endif
