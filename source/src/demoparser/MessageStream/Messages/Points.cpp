/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Points.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Points::extractDataFromBuffer(ucharbuf* _buffer)
{
  int count = getint(*_buffer);
  if (count > 0)
  {
    loopi(count)
    {
      int pcn = getint(*_buffer); int score = getint(*_buffer);
    }
  }
  else
  {
    int medals = getint(*_buffer);
    if (medals > 0)
    {
      loopi(medals)
      {
        int mcn=getint(*_buffer); int mtype=getint(*_buffer); int mitem=getint(*_buffer);
      }
    }
  }
}
