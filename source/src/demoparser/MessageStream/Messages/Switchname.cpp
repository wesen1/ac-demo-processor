/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Switchname.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Switchname::extractDataFromBuffer(ucharbuf* _buffer)
{
  getstring(newName, *_buffer);
}
