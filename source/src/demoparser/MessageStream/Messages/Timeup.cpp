/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Timeup.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Timeup::extractDataFromBuffer(ucharbuf* _buffer)
{
  currentGameMillis = getint(*_buffer);
  currentGameLimit = getint(*_buffer);
}
