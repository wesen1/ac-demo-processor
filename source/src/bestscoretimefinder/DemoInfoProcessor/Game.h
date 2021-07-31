/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../../demoparser/MessageStream/Message.h"

#ifndef DEMO_INFO_PROCESSOR_GAME
#define DEMO_INFO_PROCESSOR_GAME

class Game
{
  private:
    bool isGameModeCtf;
    bool flagsAreAtOriginalPosition[2];

  public:
    Game();
    bool getIsGameModeCtf();
    bool isFlagAtOriginalPosition(int);

    void processMessage(Message*);
};

#endif
