/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Iplist.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Iplist::extractDataFromBuffer(ucharbuf* _buffer)
{
  int clientNumber;
  do
  {
    clientNumber = getint(*_buffer);
    if (clientNumber >= 0)
    {
      clientNumbers.push_back(clientNumber);
      ips.push_back(getint(*_buffer));
    }
  } while (clientNumber >= 0 && !_buffer->overread());
}
