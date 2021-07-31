/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Editent.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Editent::extractDataFromBuffer(ucharbuf* _buffer)
{
  entityIndex = getint(*_buffer);
  type = getint(*_buffer);
  x = getint(*_buffer);
  y = getint(*_buffer);
  z = getint(*_buffer);
  attr1 = getint(*_buffer);
  attr2 = getint(*_buffer);
  attr3 = getint(*_buffer);
  attr4 = getint(*_buffer);
}
