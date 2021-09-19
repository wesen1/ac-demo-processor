/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "DemoMetaData.h"


/**
 * DemoMetaData constructor.
 *
 * @param int _timestamp The unix timestamp when the demo recording started
 * @param int _gameMode The game mode ID
 * @param std::string _mapName The map name
 * @param int _mapRevision The map revision
 */
DemoMetaData::DemoMetaData(int _timestamp, int _gameMode, std::string _mapName, int _mapRevision)
{
  timestamp = _timestamp;
  gameMode = _gameMode;
  mapName = _mapName;
  mapRevision = _mapRevision;
}


// Getters and Setters

/**
 * Returns the timestamp when the demo recording started.
 *
 * @return int The timestamp
 */
int DemoMetaData::getTimestamp()
{
  return timestamp;
}

/**
 * Returns the game mode ID.
 *
 * @return int The game mode ID
 */
int DemoMetaData::getGameMode()
{
  return gameMode;
}

/**
 * Returns the map name.
 *
 * @return std::string The map name
 */
std::string DemoMetaData::getMapName()
{
  return mapName;
}

/**
 * Returns the map revision.
 *
 * @return int The map revision
 */
int DemoMetaData::getMapRevision()
{
  return mapRevision;
}
