/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "BestScoreTimeFinder.h"

#ifndef BEST_SCORE_TIME_FINDER_FACTORY
#define BEST_SCORE_TIME_FINDER_FACTORY

class BestScoreTimeFinderFactory
{
  public:
    BestScoreTimeFinder* createBestScoreTimeFinder();
};

#endif
