/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Senddemolist.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Senddemolist::extractDataFromBuffer(ucharbuf* _buffer)
{
  int numberOfDemos = getint(*_buffer);
  if (numberOfDemos > 0)
  {
    char demoName[MAXTRANS];
    loopi(numberOfDemos)
    {
      getstring(demoName, *_buffer);
      demoNames.push_back(demoName);
    }
  }
}
