/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Initclient.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Initclient::extractDataFromBuffer(ucharbuf* _buffer)
{
  clientNumber = getint(*_buffer);
  getstring(name, *_buffer);
  loopi(2) skins[i] = getint(*_buffer);
  teamId = getint(*_buffer);
  if(demoprotocol > 1132) address = getint(*_buffer); // partial IP address
}
