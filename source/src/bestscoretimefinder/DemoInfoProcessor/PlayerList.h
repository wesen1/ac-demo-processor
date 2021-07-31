/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include <unordered_map>
#include "Player.h"
#include "../../demoparser/MessageStream/Message.h"

#ifndef DEMO_INFO_PROCESSOR_PLAYER_LIST
#define DEMO_INFO_PROCESSOR_PLAYER_LIST

class PlayerList
{
  private:
    std::unordered_map<int, Player*> players;

  public:
    void processMessage(Message*);
    Player* getPlayerByClientNumber(int);
};

#endif
