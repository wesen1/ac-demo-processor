/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "FlagScoreList.h"
#include "../../demoparser/MessageStream/Messages/Shotfx.h"
#include "../../demoparser/MessageStream/Messages/Flagmsg.h"

/**
 * FlagScore constructor.
 *
 * @param Game _game The Game state
 * @param PlayerList _playerList The Player list
 */
FlagScoreList::FlagScoreList(Game* _game, PlayerList* _playerList)
{
  game = _game;
  playerList = _playerList;
}


// Public Methods

/**
 * Processes a given Message.
 *
 * @param Message _message The Message to process
 * @param Packet _packet The Packet to which the Message belongs
 */
void FlagScoreList::processMessage(Message* _message, Packet* _packet)
{
  if (_message->getType() == SV_SPAWN)
  {
    int clientNumber = _message->getClientNumberFromParentClientMessage();
    if (clientNumber != -1)
    {
      FlagScore* flagScore = getFlagScoreByClientNumber(clientNumber);
      if (!flagScore)
      {
        flagScore = new FlagScore(playerList->getPlayerByClientNumber(clientNumber));
        flagScores[clientNumber] = flagScore;
      }
      else
      {
        flagScore->reset();
      }

      flagScore->processSpawnEvent(_packet->getTimestamp());
    }
  }

  else if (_message->getType() == SV_SHOTFX)
  {
    Shotfx* shotfxMessage = static_cast<Shotfx*>(_message);

    FlagScore* flagScore = getFlagScoreByClientNumber(shotfxMessage->senderClientNumber);
    if (flagScore) flagScore->processShotEvent(shotfxMessage->weaponId);
  }

  else if (_message->getType() == SV_FLAGMSG)
  {
    Flagmsg* flagmsgMessage = static_cast<Flagmsg*>(_message);

    FlagScore* flagScore = getFlagScoreByClientNumber(flagmsgMessage->actorClientNumber);
    if (flagScore)
    {
      switch (flagmsgMessage->flagMessageId)
      {
        case FM_PICKUP:
          flagScore->processFlagPickupEvent(game->isFlagAtOriginalPosition(flagmsgMessage->flagId));
          break;

        case FM_SCORE:
          flagScore->processScoreEvent(_packet->getTimestamp());
          break;
      }
    }
  }
}

/**
 * Fetches and pops the next finished FlagScore from the FlagScore map.
 *
 * @return FlagScore The next finished FlagScore
 */
FlagScore* FlagScoreList::popNextFinishedFlagScore()
{
  for (const std::pair<int, FlagScore*>& item : flagScores)
  {
    int clientNumber = item.first;
    FlagScore* flagScore = item.second;
    if (flagScore->isFinished())
    {
      flagScores.erase(clientNumber);
      return flagScore;
    }
  }

  return NULL;
}


// Private Methods

/**
 * Returns the FlagScore for a given client number.
 *
 * @param int _clientNumber The client number
 *
 * @return FlagScore The FlagScore for the client number
 */
FlagScore* FlagScoreList::getFlagScoreByClientNumber(int _clientNumber)
{
  std::unordered_map<int,FlagScore*>::const_iterator foundItem = flagScores.find(_clientNumber);
  if (foundItem != flagScores.end())
  {
    return foundItem->second;
  }
  else return NULL;
}
