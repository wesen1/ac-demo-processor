/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_{{MESSAGE_IDENTIFIER}}
#define PARSER_MESSAGE_{{MESSAGE_IDENTIFIER}}

class {{MESSAGE_CLASS_NAME}}: public Message
{
  public:
    {{MESSAGE_CLASS_NAME}}(): Message({{MESSAGE_CONSTANT_NAME}})
    {
    }

    void extractDataFromBuffer(ucharbuf*);
};

#endif
