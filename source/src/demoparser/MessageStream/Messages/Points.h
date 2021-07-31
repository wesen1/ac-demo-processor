/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_POINTS
#define PARSER_MESSAGE_POINTS

class Points: public Message
{
  public:
    Points(): Message(SV_POINTS)
    {
    }

    void extractDataFromBuffer(ucharbuf*);
};

#endif
