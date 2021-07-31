/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_TEAMTEXTME
#define PARSER_MESSAGE_TEAMTEXTME

class Teamtextme: public Message
{
  public:
    using Message::Message;

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
    char message[MAXTRANS];
};

#endif
