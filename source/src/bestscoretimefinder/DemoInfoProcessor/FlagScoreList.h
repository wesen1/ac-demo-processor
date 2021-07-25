/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include <unordered_map>
#include "Game.h"
#include "PlayerList.h"
#include "FlagScore.h"
#include "../../demoparser/MessageStream/Message.h"
#include "../../demoparser/PacketStream/Packet.h"

#ifndef DEMO_INFO_PROCESSOR_FLAG_SCORE_LIST
#define DEMO_INFO_PROCESSOR_FLAG_SCORE_LIST

class FlagScoreList
{
  private:
    Game* game;
    PlayerList* playerList;
    std::unordered_map<int, FlagScore*> flagScores;
    FlagScore* getFlagScoreByClientNumber(int);

  public:
    FlagScoreList(Game*, PlayerList*);
    void processMessage(Message*, Packet*);
    FlagScore* popNextFinishedFlagScore();
};

#endif
