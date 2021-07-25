/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Discscores.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Discscores::extractDataFromBuffer(ucharbuf* _buffer)
{
  int team;
  do
  {
    team = getint(*_buffer);
    if (team >= 0)
    {
      getstring(playerName, *_buffer);
      numberOfFlags = getint(*_buffer);
      numberOfFrags = getint(*_buffer);
      numberOfDeaths = getint(*_buffer);
      numberOfPoints = getint(*_buffer);
    }

  } while (team >= 0);
}
