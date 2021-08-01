/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "bestscoretimefinder/BestScoreTimeFinderFactory.h"
#include "bestscoretimefinder/BestScoreTimeFinder.h"
#include "cjson/cJSON.h"

#ifndef COMMAND_FIND_BEST_SCORE_TIMES
#define COMMAND_FIND_BEST_SCORE_TIMES

class FindBestScoreTimes
{
  public:
    void execute(std::string);

  private:
    cJSON* generateJson(std::unordered_map<std::string, FlagScore*> _flagScores);
};

#endif
