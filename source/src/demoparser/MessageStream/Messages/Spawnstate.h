/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SPAWNSTATE
#define PARSER_MESSAGE_SPAWNSTATE

class Spawnstate: public Message
{
  public:
    Spawnstate(): Message(SV_SPAWNSTATE)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int lifesequence;
    int health;
    int armour;
    int primaryWeaponId;
    int selectedWeaponId;
    int arenaspawn;
    int ammo[NUMGUNS];
    int mag[NUMGUNS];
};

#endif
