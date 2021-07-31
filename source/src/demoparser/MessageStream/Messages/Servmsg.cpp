/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Servmsg.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Servmsg::extractDataFromBuffer(ucharbuf* _buffer)
{
  getstring(message, *_buffer);
}
