/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_RESUME
#define PARSER_MESSAGE_RESUME

class Resume: public Message
{
  public:
    Resume(): Message(SV_RESUME)
    {
    }

    void extractDataFromBuffer(ucharbuf*);
};

#endif
