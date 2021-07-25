/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Servinfo.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Servinfo::extractDataFromBuffer(ucharbuf* _buffer)
{
  clientNumber = getint(*_buffer);
  protocolVersion = getint(*_buffer);
  sessionId = getint(*_buffer);
  isPasswordProtectedServer = getint(*_buffer);
}
