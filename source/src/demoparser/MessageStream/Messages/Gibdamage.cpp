/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Gibdamage.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Gibdamage::extractDataFromBuffer(ucharbuf* _buffer)
{
  targetClientNumber = getint(*_buffer);
  actorClientNumber = getint(*_buffer);
  weaponId = getint(*_buffer);
  damage = getint(*_buffer);
  armour = getint(*_buffer);
  health = getint(*_buffer);
}
