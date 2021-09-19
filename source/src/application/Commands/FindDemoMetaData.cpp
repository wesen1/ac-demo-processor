/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "FindDemoMetaData.h"
#include "../../demoparser/DemoParser.h"
#include "../../demoparser/ParsedDemo.h"
#include "../../demometadatafinder/DemoMetaDataFinder.h"


// Public Methods

/**
 * Finds the meta data for a given demo and prints the results as a JSON string.
 *
 * @param std::string _demoFilePath The path to the demo file to search for meta data
 */
void FindDemoMetaData::execute(std::string _demoFilePath)
{
  // Parse the input demo
  DemoParser* demoParser = new DemoParser();
  ParsedDemo* parsedDemo = demoParser->parseDemo(strdup(_demoFilePath.c_str()));

  DemoMetaDataFinder* demoMetaDataFinder = new DemoMetaDataFinder();
  DemoMetaData* demoMetaData = demoMetaDataFinder->findDemoMetaData(parsedDemo);

  cJSON* json = generateJson(demoMetaData);
  printf("%s\n", cJSON_Print(json));
  cJSON_Delete(json);
}


// Private Methods

/**
 * Generates and returns a cJSON oject from a given DemoMetaData instance.
 *
 * @param DemoMetaData _demoMetaData The DemoMetaData
 *
 * @return cJSON The generated cJSON object
 */
cJSON* FindDemoMetaData::generateJson(DemoMetaData* _demoMetaData)
{
  cJSON* jsonRoot = cJSON_CreateObject();
  if (!jsonRoot)
  {
    printf("Error before: [%s]\n", cJSON_GetErrorPtr());
    return NULL;
  }

  cJSON_AddItemToObject(
    jsonRoot,
    "timestamp",
    cJSON_CreateNumber(_demoMetaData->getTimestamp())
  );

  cJSON_AddItemToObject(
    jsonRoot,
    "gameMode",
    cJSON_CreateString(acronymmodestr(_demoMetaData->getGameMode()))
  );

  cJSON_AddItemToObject(
    jsonRoot,
    "mapName",
    cJSON_CreateString(_demoMetaData->getMapName().c_str())
  );

  cJSON_AddItemToObject(
    jsonRoot,
    "mapRevision",
    cJSON_CreateNumber(_demoMetaData->getMapRevision())
  );

  return jsonRoot;
}
