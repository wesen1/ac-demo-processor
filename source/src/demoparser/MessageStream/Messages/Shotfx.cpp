/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Shotfx.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Shotfx::extractDataFromBuffer(ucharbuf* _buffer)
{
  senderClientNumber = getint(*_buffer);
  weaponId = getint(*_buffer);
  loopk(3) to[k] = getint(*_buffer);
}
