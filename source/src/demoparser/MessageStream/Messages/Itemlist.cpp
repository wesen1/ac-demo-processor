/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Itemlist.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Itemlist::extractDataFromBuffer(ucharbuf* _buffer)
{
  int itemId;
  do
  {
    itemId = getint(*_buffer);
    if (itemId != -1) itemIds.push_back(itemId);
  }
  while (itemId != -1);
}
