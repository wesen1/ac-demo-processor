/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "FlagScoreFinder.h"


/**
 * FlagScoreFinder constructor.
 *
 * @param Game _game The game state
 * @param PlayerList _playerList The player list
 * @param FlagScoreList _flagScoreList The flag score list
 */
FlagScoreFinder::FlagScoreFinder(Game* _game, PlayerList* _playerList, FlagScoreList* _flagScoreList)
{
  game = _game;
  playerList = _playerList;
  flagScoreList = _flagScoreList;
}


// Public Methods

/**
 * Finds the next FlagScore in a given Packet stream.
 *
 * @param PacketStream _packetStream The Packet stream to process
 *
 * @return FlagScore The next FlagScore in the given Packet stream
 */
FlagScore* FlagScoreFinder::findNextFlagScore(PacketStream* _packetStream)
{
  FlagScore* nextFlagScore;
  Packet* nextPacket;
  do
  {
    nextPacket = _packetStream->getNextPacket();
    if (nextPacket)
    {
      Message* nextMessage;
      do
      {
        nextFlagScore = flagScoreList->popNextFinishedFlagScore();
        if (nextFlagScore) return nextFlagScore;

        nextMessage = nextPacket->getMessageStream()->getNextMessage();
        if (nextMessage)
        {
          //clientlogf("Parsed message of type %s (%d)", nextMessage->getTypeName(), nextMessage->getType());

          playerList->processMessage(nextMessage);
          flagScoreList->processMessage(nextMessage, nextPacket);

          game->processMessage(nextMessage);
          if (!game->getIsGameModeCtf()) return NULL;
        }
        //else clientlogf("Found no next message");
      }
      while (nextMessage);
    }
  }
  while (nextPacket);

  return NULL;
}
