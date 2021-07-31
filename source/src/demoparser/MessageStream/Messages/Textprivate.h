/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_TEXTPRIVATE
#define PARSER_MESSAGE_TEXTPRIVATE

class Textprivate: public Message
{
  public:
    Textprivate(): Message(SV_TEXTPRIVATE)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
    char message[MAXTRANS];
};

#endif
