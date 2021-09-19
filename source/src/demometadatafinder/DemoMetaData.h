/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include <string>

#ifndef DEMO_META_DATA
#define DEMO_META_DATA

class DemoMetaData
{
  private:
    int timestamp;
    int gameMode;
    std::string mapName;
    int mapRevision;

  public:
    DemoMetaData(int, int, std::string, int);

    int getTimestamp();
    int getGameMode();
    std::string getMapName();
    int getMapRevision();
};

#endif
