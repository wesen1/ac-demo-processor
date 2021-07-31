/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../../demoparser/MessageStream/Messages/Initclient.h"
#include "../../demoparser/MessageStream/Messages/Switchname.h"

#ifndef DEMO_INFO_PROCESSOR_PLAYER
#define DEMO_INFO_PROCESSOR_PLAYER

class Player
{
  private:
    void changeName(char*);
    int clientNumber;
    char* name;
    int ip;

  public:
    Player(int);
    Player(Player*);

    int getClientNumber();
    char* getName();
    int getIp();

    void processInitclientMessage(Initclient*);
    void processSwitchnameMessage(Switchname*);
    std::string getIpString();
};

#endif
