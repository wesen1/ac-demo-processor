/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../demoparser/DemoParser.h"
#include "FlagScoreFinder.h"
#include "DemoInfoProcessor/FlagScore.h"

#ifndef BEST_SCORE_TIME_FINDER
#define BEST_SCORE_TIME_FINDER

class BestScoreTimeFinder
{
  private:
    DemoParser* demoParser;
    FlagScoreFinder* flagScoreFinder;
    bool flagScoreWasDoneByTargetPlayer(FlagScore*, const char*, const char*);

  public:
    BestScoreTimeFinder(DemoParser*, FlagScoreFinder*);
    FlagScore* findBestScoreTime(char*, const char*, const char*);
};

#endif
