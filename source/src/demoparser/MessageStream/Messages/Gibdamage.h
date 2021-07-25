/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_GIBDAMAGE
#define PARSER_MESSAGE_GIBDAMAGE

class Gibdamage: public Message
{
  public:
    using Message::Message;

    void extractDataFromBuffer(ucharbuf*);


    int targetClientNumber;
    int actorClientNumber;
    int weaponId;
    int damage;
    int armour;
    int health;
};

#endif
