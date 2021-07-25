/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SPAWN
#define PARSER_MESSAGE_SPAWN

class Spawn: public Message
{
  public:
    Spawn(): Message(SV_SPAWN)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int lifesequence;
    int health;
    int armour;
    int selectedWeaponId;
    int ammo[NUMGUNS];
    int mag[NUMGUNS];
};

#endif
