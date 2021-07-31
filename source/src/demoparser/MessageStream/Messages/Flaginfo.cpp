/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Flaginfo.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Flaginfo::extractDataFromBuffer(ucharbuf* _buffer)
{
  flagId = getint(*_buffer);
  flagState = getint(*_buffer);

  switch(flagState)
  {
    case CTFF_STOLEN:
      actorClientNumber = getint(*_buffer);
      break;

    case CTFF_DROPPED:
      x = getuint(*_buffer);
      y = getuint(*_buffer);
      z = getuint(*_buffer);
      break;

    case CTFF_INBASE:
    case CTFF_IDLE:
      break;
  }
}
