/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Game.h"
#include "../../demoparser/MessageStream/Messages/Gamemode.h"
#include "../../demoparser/MessageStream/Messages/Flagmsg.h"


/**
 * Game constructor.
 */
Game::Game()
{
  isGameModeCtf = true;
  loopi(2)
  {
    flagsAreAtOriginalPosition[i] = true;
  }
}


// Getters and Setters

/**
 * Returns whether the game mode of the Game state is CTF.
 *
 * @return bool True if the game mode of the Game state is CTF, false if it is something else
 */
bool Game::getIsGameModeCtf()
{
  return isGameModeCtf;
}


// Public Methods

/**
 * Returns whether a given flag currently is located at its original position.
 *
 * @param int _flagId The ID of the flag
 *
 * @return bool True if the flag is currently located at its original position, false otherwise
 */
bool Game::isFlagAtOriginalPosition(int _flagId)
{
  return flagsAreAtOriginalPosition[_flagId];
}

/**
 * Processes a given Message.
 *
 * @param Message _message The Message to process
 */
void Game::processMessage(Message* _message)
{
  // TODO: Replace by SV_MAPCHANGE check
  if (_message->getType() == SV_GAMEMODE)
  {
    Gamemode* gamemodeMessage = static_cast<Gamemode*>(_message);
    isGameModeCtf = (gamemodeMessage->nextmode == GMODE_CTF);
  }

  else if (_message->getType() == SV_FLAGMSG)
  {
    Flagmsg* flagmsgMessage = static_cast<Flagmsg*>(_message);
    switch(flagmsgMessage->flagMessageId)
    {
      case FM_RESET:
      case FM_RETURN:
        flagsAreAtOriginalPosition[flagmsgMessage->flagId] = true;
        break;

      case FM_PICKUP:
        flagsAreAtOriginalPosition[flagmsgMessage->flagId] = false;
        break;

      case FM_SCORE:
        flagsAreAtOriginalPosition[flagmsgMessage->flagId] = true;
        break;
    }
  }
}
