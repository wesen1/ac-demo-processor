/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "FlagScore.h"


/**
 * FlagScore constructor.
 *
 * @param Player _player The Player to which the FlagScore belongs
 */
FlagScore::FlagScore(Player* _player)
{
  player = _player;
  reset();
}


// Getters and Setters

/**
 * Returns the player.
 *
 * @return Player The player
 */
Player* FlagScore::getPlayer()
{
  return player;
}

/**
 * Returns whether the flag was stolen from its original position.
 *
 * @return bool True if the flag was stolen from its original position, false otherwise
 */
bool FlagScore::getWasFlagStolenFromOriginalPosition()
{
  return wasFlagStolenFromOriginalPosition;
}

/**
 * Returns the weapon ID.
 *
 * @return int The weapon ID
 */
int FlagScore::getWeaponId()
{
  return weaponId;
}

/**
 * Returns the spawn timestamp.
 *
 * @return int The spawn timestamp
 */
int FlagScore::getSpawnTimestamp()
{
  return spawnTimestamp;
}

/**
 * Returns the score timestamp.
 *
 * @return int The score timestamp
 */
int FlagScore::getScoreTimestamp()
{
  return scoreTimestamp;
}


// Public Methods

/**
 * Calculates and returns the score time.
 *
 * @return int The calculated score time
 */
int FlagScore::calculateScoreTime()
{
  if (isFinished()) return scoreTimestamp - spawnTimestamp;
  else return -1;
}


/**
 * Processes a "Player spawned" event.
 *
 * @param int _timestamp The "Player spawned" event timestamp
 */
void FlagScore::processSpawnEvent(int _timestamp)
{
  spawnTimestamp = _timestamp;
}

/**
 * Processes a "Player shot" event.
 *
 * @param int _weaponId The ID of the weapon that the player shot with
 */
void FlagScore::processShotEvent(int _weaponId)
{
  if (_weaponId == GUN_KNIFE || _weaponId == GUN_GRENADE)
  { // Do nothing
  }
  else if (_weaponId == GUN_PISTOL || _weaponId == GUN_AKIMBO)
  { // Change score attempt weapon to PISTOL if it is currently KNIFE
    if (weaponId == GUN_KNIFE)
    {
      weaponId = GUN_PISTOL;
    }
  }
  else
  { // Primary weapon was used
    if (weaponId == GUN_KNIFE ||
        weaponId == GUN_PISTOL)
    {
      weaponId = _weaponId;
    }
  }
}

/**
 * Processes a "Player picked up flag" event.
 *
 * @param bool _wasFlagAtOriginalPosition True if the picked up flag was located at its original position, false otherwise
 */
void FlagScore::processFlagPickupEvent(bool _wasFlagAtOriginalPosition)
{
  if (_wasFlagAtOriginalPosition)
  { // One "steal flag from original position" event is sufficient to make the wasFlagStolenFromOriginalPosition flag "true" permanently
    wasFlagStolenFromOriginalPosition = true;
  }
}

/**
 * Processes a "Player scored" event.
 *
 * @param int _timestamp The "Player scored" event timestamp
 */
void FlagScore::processScoreEvent(int _timestamp)
{
  scoreTimestamp = _timestamp;
}

/**
 * Returns whether this FlagScore is finished.
 *
 * @return bool True if this FlagScore is finished, false otherwise
 */
bool FlagScore::isFinished()
{
  return (spawnTimestamp != -1 && scoreTimestamp != -1);
}

/**
 * Resets this FlagScore to its initial state.
 */
void FlagScore::reset()
{
  wasFlagStolenFromOriginalPosition = false;
  weaponId = GUN_KNIFE;
  spawnTimestamp = -1;
  scoreTimestamp = -1;
}
