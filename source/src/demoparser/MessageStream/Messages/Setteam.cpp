/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Setteam.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Setteam::extractDataFromBuffer(ucharbuf* _buffer)
{
  clientNumber = getint(*_buffer);
  newTeamId = getint(*_buffer);
}
