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
 * Finds and returns the FlagScore's with the lowest score time per player name in a given demo.
 *
 * @param char[] _demoFilePath The path to the demo file to parse
 *
 * @return std::unordered_map<std::string, FlagScore*> The list of FlagScore's
 */
std::unordered_map<std::string, FlagScore*> BestScoreTimeFinder::findBestScoreTimes(char* _demoFilePath)
{
  std::unordered_map<std::string, FlagScore*> bestPlayerFlagScores;

  ParsedDemo* parsedDemo = demoParser->parseDemo(_demoFilePath);
  if (parsedDemo)
  {
    /*
    clientlogf("demoheader data:");
    clientlogf("magic: %s", parsedDemo->getDemoHeader()->magic);
    clientlogf("version: %d", parsedDemo->getDemoHeader()->version);
    clientlogf("protocol: %d", parsedDemo->getDemoHeader()->protocol);
    clientlogf("desc: %s", parsedDemo->getDemoHeader()->desc);
    clientlogf("plist: %s", parsedDemo->getDemoHeader()->plist);
    */

    FlagScore* nextFlagScore;
    do
    {
      nextFlagScore = flagScoreFinder->findNextFlagScore(parsedDemo->getPacketStream());
      if (nextFlagScore &&
          nextFlagScore->getWasFlagStolenFromOriginalPosition())
      { // Found a valid flag score
        std::string playerIdentifier;
        playerIdentifier += nextFlagScore->getPlayer()->getIpString();
        playerIdentifier += "_";
        playerIdentifier += nextFlagScore->getPlayer()->getName();

        FlagScore* bestFlagScore = NULL;
        if (bestPlayerFlagScores.find(playerIdentifier) != bestPlayerFlagScores.end())
        {
          bestFlagScore = bestPlayerFlagScores[playerIdentifier];
        }

        if (!bestFlagScore ||
            nextFlagScore->calculateScoreTime() < bestFlagScore->calculateScoreTime())
        {
          // Copy the FlagScore object to prevent further modifications by the FlagScoreFinder
          FlagScore* copiedFlagScore = new FlagScore(nextFlagScore);
          bestPlayerFlagScores[playerIdentifier] = copiedFlagScore;
        }
      }
    }
    while (nextFlagScore);
  }

  return bestPlayerFlagScores;
}
