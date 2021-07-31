/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "BestScoreTimeFinder.h"


/**
 * BestScoreTimeFinder constructor.
 *
 * @param DemoParser _demoParser The DemoParser to use to parse demos
 * @param FlagScoreFinder _flagScoreFinder The FlagScoreFinder to use to find flag scores in parsed demo data
 */
BestScoreTimeFinder::BestScoreTimeFinder(DemoParser* _demoParser, FlagScoreFinder* _flagScoreFinder)
{
  demoParser = _demoParser;
  flagScoreFinder = _flagScoreFinder;
}


// Public Methods

/**
 * Finds and returns the FlagScore with the lowest score time for a given target player name and IP in a
 * given demo.
 *
 * @param char[] _demoFilePath The path to the demo file path to parse
 * @param char[] _targetPlayerName The target player name
 * @param char[] _targetPlayerIp The target player IP
 */
FlagScore* BestScoreTimeFinder::findBestScoreTime(char* _demoFilePath, const char* _targetPlayerName, const char* _targetPlayerIp)
{
  FlagScore* bestFlagScore = NULL;

  ParsedDemo* parsedDemo = demoParser->parseDemo(_demoFilePath);
  if (parsedDemo)
  {
    clientlogf("demoheader data:");
    clientlogf("magic: %s", parsedDemo->getDemoHeader()->magic);
    clientlogf("version: %d", parsedDemo->getDemoHeader()->version);
    clientlogf("protocol: %d", parsedDemo->getDemoHeader()->protocol);
    clientlogf("desc: %s", parsedDemo->getDemoHeader()->desc);
    clientlogf("plist: %s", parsedDemo->getDemoHeader()->plist);

    FlagScore* nextFlagScore;
    do
    {
      nextFlagScore = flagScoreFinder->findNextFlagScore(parsedDemo->getPacketStream());
      if (nextFlagScore &&
          nextFlagScore->getWasFlagStolenFromOriginalPosition() &&
          flagScoreWasDoneByTargetPlayer(nextFlagScore, _targetPlayerName, _targetPlayerIp))
      {
        clientlogf("Found relevant flag score: %d milliseconds by %s (%d, %s) with weapon %d",
                   nextFlagScore->calculateScoreTime(),
                   nextFlagScore->getPlayer()->getName(),
                   nextFlagScore->getPlayer()->getClientNumber(),
                   nextFlagScore->getPlayer()->getIpString().c_str(),
                   nextFlagScore->getWeaponId()
        );

        if (!bestFlagScore ||
            nextFlagScore->calculateScoreTime() < bestFlagScore->calculateScoreTime())
        {
          bestFlagScore = nextFlagScore;
        }
      }
    }
    while (nextFlagScore);
  }

  return bestFlagScore;
}


// Private Methods

/**
 * Returns whether a given FlagScore was done by the target player.
 *
 * @param FlagScore _flagScore The FlagScore to check
 * @param char[] _targetPlayerName The target player name
 * @param char[] _targetPlayerIp The target player IP
 *
 * @return bool True if the given FlagScore was done by the target player, false otherwise
 */
bool BestScoreTimeFinder::flagScoreWasDoneByTargetPlayer(FlagScore* _flagScore, const char* _targetPlayerName, const char* _targetPlayerIp)
{
  char* playerName = _flagScore->getPlayer()->getName();
  bool playerNameMatchesTargetName = (_targetPlayerName == NULL || !strcmp(playerName, _targetPlayerName));

  const char* playerIp = _flagScore->getPlayer()->getIpString().c_str();
  bool playerIpMatchesTargetIp = (_targetPlayerIp == NULL || !strcmp(playerIp, _targetPlayerIp));

  return (playerNameMatchesTargetName && playerIpMatchesTargetIp);
}
