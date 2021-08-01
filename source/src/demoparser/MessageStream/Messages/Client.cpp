/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Client.h"
#include <algorithm>


// Public Methods

/**
 * Adds a child message to this Client message.
 *
 * @param Message _childMessage The child message to add
 */
void Client::addChildMessage(Message* _childMessage)
{
  childMessages.push_back(_childMessage);
  _childMessage->setParentClientMessage(this);
}

/**
 * Removes a child message from this Client message.
 *
 * @param Message _childMessage The child message to remove
 */
void Client::removeChildMessage(Message* _childMessage)
{
  childMessages.erase(std::remove(childMessages.begin(), childMessages.end(), _childMessage), childMessages.end());
}

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Client::extractDataFromBuffer(ucharbuf* _buffer)
{
  clientNumber = getint(*_buffer);
  int clientMessagesBufferLength = getuint(*_buffer);
  clientMessagesBuffer = _buffer->subbuf(clientMessagesBufferLength);
}
