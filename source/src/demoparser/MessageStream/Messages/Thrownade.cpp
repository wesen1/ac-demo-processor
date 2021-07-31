/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Thrownade.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Thrownade::extractDataFromBuffer(ucharbuf* _buffer)
{
  loopk(3) from[k] = getint(*_buffer);
  loopk(3) to[k] = getint(*_buffer);
  nademillis = getint(*_buffer);
}
