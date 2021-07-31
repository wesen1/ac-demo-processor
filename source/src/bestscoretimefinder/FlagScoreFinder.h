/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "DemoInfoProcessor/Game.h"
#include "DemoInfoProcessor/PlayerList.h"
#include "DemoInfoProcessor/FlagScoreList.h"
#include "DemoInfoProcessor/FlagScore.h"
#include "../demoparser/PacketStream/PacketStream.h"

#ifndef FLAG_SCORE_FINDER
#define FLAG_SCORE_FINDER

class FlagScoreFinder
{
  private:
    Game* game;
    PlayerList* playerList;
    FlagScoreList* flagScoreList;

  public:
    FlagScoreFinder(Game*, PlayerList*, FlagScoreList*);
    FlagScore* findNextFlagScore(PacketStream*);
};

#endif
