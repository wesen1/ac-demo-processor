/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Edith.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Edith::extractDataFromBuffer(ucharbuf* _buffer)
{
  x = getint(*_buffer);
  y = getint(*_buffer);
  xs = getint(*_buffer);
  ys = getint(*_buffer);
  v = getint(*_buffer);

  switch(getType())
  {
    case SV_EDITH:
      heightxy = getint(*_buffer);
      break;
    case SV_EDITT:
      texxy = getint(*_buffer);
      break;
    case SV_EDITS:
    case SV_EDITD:
    case SV_EDITE:
      break;
  }
}
