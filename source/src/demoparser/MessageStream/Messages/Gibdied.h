/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_GIBDIED
#define PARSER_MESSAGE_GIBDIED

class Gibdied: public Message
{
  public:
    using Message::Message;

    void extractDataFromBuffer(ucharbuf*);


    int targetClientNumber;
    int actorClientNumber;
    int frags;
    int weaponId;
};

#endif
