/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Switchskin.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Switchskin::extractDataFromBuffer(ucharbuf* _buffer)
{
  loopi(2)
  {
    skins[i] = getint(*_buffer);
  }
}
