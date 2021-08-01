/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Player.h"

#ifndef DEMO_INFO_PROCESSOR_FLAG_SCORE
#define DEMO_INFO_PROCESSOR_FLAG_SCORE

class FlagScore
{
  private:
    Player* player;
    bool wasFlagStolenFromOriginalPosition;
    int weaponId;
    int spawnTimestamp;
    int scoreTimestamp;

  public:

    FlagScore(Player*);
    FlagScore(FlagScore*);

    Player* getPlayer();
    bool getWasFlagStolenFromOriginalPosition();
    int getWeaponId();
    int getSpawnTimestamp();
    int getScoreTimestamp();

    int calculateScoreTime();

    void processSpawnEvent(int);
    void processShotEvent(int);
    void processFlagPickupEvent(bool);
    void processScoreEvent(int);
    bool isFinished();
    void reset();
};

#endif
