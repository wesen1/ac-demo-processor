/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "BestScoreTimeFinderFactory.h"
#include "bestscoretimefinder/DemoInfoProcessor/Game.h"
#include "bestscoretimefinder/DemoInfoProcessor/PlayerList.h"
#include "bestscoretimefinder/DemoInfoProcessor/FlagScoreList.h"
#include "bestscoretimefinder/FlagScoreFinder.h"
#include "../demoparser/DemoParser.h"


// Public Methods

/**
 * Creates and returns a new BestScoreTimeFinder instance.
 *
 * @return BestScoreTimeFinder The created BestScoreTimeFinder instance
 */
BestScoreTimeFinder* BestScoreTimeFinderFactory::createBestScoreTimeFinder()
{
  Game* game = new Game();
  PlayerList* playerList = new PlayerList();
  return new BestScoreTimeFinder(
    new DemoParser(),
    new FlagScoreFinder(
      game,
      playerList,
      new FlagScoreList(game, playerList)
    )
  );
}
