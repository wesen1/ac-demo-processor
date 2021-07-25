/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Itemacc.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Itemacc::extractDataFromBuffer(ucharbuf* _buffer)
{
  itemId = getint(*_buffer);
  clientNumber = getint(*_buffer);
}
