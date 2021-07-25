/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Hitpush.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Hitpush::extractDataFromBuffer(ucharbuf* _buffer)
{
  weaponId = getint(*_buffer);
  damage = getint(*_buffer);
  loopk(3) dir[k] = getint(*_buffer);
}
