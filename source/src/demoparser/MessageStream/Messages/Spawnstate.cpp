/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Spawnstate.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Spawnstate::extractDataFromBuffer(ucharbuf* _buffer)
{
  lifesequence = getint(*_buffer);
  health = getint(*_buffer);
  armour = getint(*_buffer);
  primaryWeaponId = getint(*_buffer);
  selectedWeaponId = getint(*_buffer);
  arenaspawn = getint(*_buffer);
  loopi(NUMGUNS) ammo[i] = getint(*_buffer);
  loopi(NUMGUNS) mag[i] = getint(*_buffer);
}
