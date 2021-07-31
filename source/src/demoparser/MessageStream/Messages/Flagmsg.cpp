/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Flagmsg.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Flagmsg::extractDataFromBuffer(ucharbuf* _buffer)
{
  flagId = getint(*_buffer);
  flagMessageId = getint(*_buffer);
  actorClientNumber = getint(*_buffer);

  if (flagMessageId == FM_KTFSCORE) flagtime = getint(*_buffer);
  else flagtime = -1;
}
