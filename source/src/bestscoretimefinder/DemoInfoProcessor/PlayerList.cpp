/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "PlayerList.h"
#include "../../demoparser/MessageStream/Messages/Initclient.h"


// Public Methods

/**
 * Processes a given Message.
 *
 * @param Message _message The Message to process
 */
void PlayerList::processMessage(Message* _message)
{
  if (_message->getType() == SV_INITCLIENT)
  {
    Initclient* initclientMessage = static_cast<Initclient*>(_message);
    int clientNumber = initclientMessage->clientNumber;

    Player* player = getPlayerByClientNumber(clientNumber);
    if (!player)
    {
      player = new Player(initclientMessage->clientNumber);
      players[initclientMessage->clientNumber] = player;
    }

    player->processInitclientMessage(initclientMessage);
  }

  else if (_message->getType() == SV_SWITCHNAME)
  {
    Switchname* switchnameMessage = static_cast<Switchname*>(_message);
    int clientNumber = switchnameMessage->getClientNumberFromParentClientMessage();

    Player* player = getPlayerByClientNumber(clientNumber);
    if (player)
    {
      player->processSwitchnameMessage(switchnameMessage);
    }
  }
}

/**
 * Returns the current Player for a given client number.
 *
 * @param int _clientNumber The client number
 *
 * @return Player The Player for the given client number
 */
Player* PlayerList::getPlayerByClientNumber(int _clientNumber)
{
  std::unordered_map<int, Player*>::const_iterator foundItem = players.find(_clientNumber);
  if (foundItem != players.end())
  {
    return foundItem->second;
  }
  else return NULL;
}
