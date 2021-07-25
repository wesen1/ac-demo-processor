/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Welcome.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Welcome::extractDataFromBuffer(ucharbuf* _buffer)
{
  joining = getint(*_buffer);
}
