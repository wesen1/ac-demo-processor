/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "FindBestScoreTimes.h"


// Public Methods

/**
 * Finds the best score times per player name in a given demo and prints the results as a JSON string.
 *
 * @param std::string _demoFilePath The path to the demo file to search for player score times
 */
void FindBestScoreTimes::execute(std::string _demoFilePath)
{
  BestScoreTimeFinderFactory* bestScoreTimeFinderFactory = new BestScoreTimeFinderFactory();
  BestScoreTimeFinder* bestScoreTimeFinder = bestScoreTimeFinderFactory->createBestScoreTimeFinder();

  std::unordered_map<std::string, FlagScore*> flagScores = bestScoreTimeFinder->findBestScoreTimes(strdup(_demoFilePath.c_str()));

  cJSON* json = generateJson(flagScores);
  printf("%s\n", cJSON_Print(json));
  cJSON_Delete(json);
}


// Private Methods

/**
 * Generates and returns a cJSON oject from a given list of best player Flagscore's.
 *
 * @param std::unordered_map<std::string, FlagScore*> _flagScores The best player Flagscore's
 *
 * @return cJSON The generated cJSON object
 */
cJSON* FindBestScoreTimes::generateJson(std::unordered_map<std::string, FlagScore*> _flagScores)
{
  cJSON* jsonRoot = cJSON_CreateObject();
  if (!jsonRoot)
  {
    printf("Error before: [%s]\n", cJSON_GetErrorPtr());
    return NULL;
  }

  cJSON* flagScoreJsonArray = cJSON_CreateArray();
  cJSON_AddItemToObject(jsonRoot, "bestScoresPerPlayer", flagScoreJsonArray);

  for (std::pair<std::string, FlagScore*> item : _flagScores)
  {
    FlagScore* flagScore = item.second;
    cJSON* flagScoreJson = cJSON_CreateObject();

    cJSON_AddItemToObject(
      flagScoreJson,
      "clientNumber",
      cJSON_CreateNumber(flagScore->getPlayer()->getClientNumber())
    );

    cJSON_AddItemToObject(
      flagScoreJson,
      "ip",
      cJSON_CreateString(flagScore->getPlayer()->getIpString().c_str())
    );

    cJSON_AddItemToObject(
      flagScoreJson,
      "name",
      cJSON_CreateString(flagScore->getPlayer()->getName())
    );

    cJSON_AddItemToObject(
      flagScoreJson,
      "scoreTimeInMilliseconds",
      cJSON_CreateNumber(flagScore->calculateScoreTime())
    );

    cJSON_AddItemToObject(
      flagScoreJson,
      "weaponId",
      cJSON_CreateNumber(flagScore->getWeaponId())
    );

    cJSON_AddItemToObject(
      flagScoreJson,
      "startTimestamp",
      cJSON_CreateNumber(flagScore->getSpawnTimestamp())
    );

    cJSON_AddItemToObject(
      flagScoreJson,
      "endTimestamp",
      cJSON_CreateNumber(flagScore->getScoreTimestamp())
    );

    cJSON_AddItemToArray(flagScoreJsonArray, flagScoreJson);
  }

  return jsonRoot;
}
