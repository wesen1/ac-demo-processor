/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Mapchange.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Mapchange::extractDataFromBuffer(ucharbuf* _buffer)
{
  getstring(mapName, *_buffer);
  gameMode = getint(*_buffer);
  downloadable = getint(*_buffer);
  revision = getint(*_buffer);
}
