/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../demoparser/DemoParser.h"
#include "FlagScoreFinder.h"
#include "DemoInfoProcessor/FlagScore.h"
#include <unordered_map>

#ifndef BEST_SCORE_TIME_FINDER
#define BEST_SCORE_TIME_FINDER

class BestScoreTimeFinder
{
  private:
    DemoParser* demoParser;
    FlagScoreFinder* flagScoreFinder;

  public:
    BestScoreTimeFinder(DemoParser*, FlagScoreFinder*);
    std::unordered_map<std::string, FlagScore*> findBestScoreTimes(char*);
};

#endif
