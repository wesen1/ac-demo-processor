/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "DemoMetaDataFinder.h"
#include <ctime>
#include <regex>


// Public Methods

/**
 * Generates and returns a DemoMetaData instance from a given ParsedDemo.
 *
 * @param ParsedDemo _parsedDemo The ParsedDemo to generate the DemoMetaData instance from
 *
 * @return DemoMetaData The generated DemoMetaData instance
 */
DemoMetaData* DemoMetaDataFinder::findDemoMetaData(ParsedDemo* _parsedDemo)
{
  int timestamp = extractTimestampFromDemoHeader(_parsedDemo->getDemoHeader());

  int gameMode = -1;
  std::string mapName("");
  int mapRevision = -1;

  Mapchange* mapchangeMessage = extractMapchangeMessageFromParsedDemo(_parsedDemo);
  if (mapchangeMessage)
  {
    gameMode = mapchangeMessage->gameMode;
    mapName = mapchangeMessage->mapName;
    mapRevision = mapchangeMessage->revision;
  }

  return new DemoMetaData(timestamp, gameMode, mapName, mapRevision);
}


// Private Methods

/**
 * Extracts and returns the demo recording start timestamp from a given demo header.
 *
 * @param demoheader _demoHeader The demo header to extract the demo recording start timestamp from
 *
 * @return int The extracted demo recording start timestamp
 */
int DemoMetaDataFinder::extractTimestampFromDemoHeader(demoheader* _demoHeader)
{
  std::string description(_demoHeader->desc);

  std::regex dateTimeStringPattern("[^,]+,[^,]+, (.{24})");
  std::smatch matches;
  if (!std::regex_search(description, matches, dateTimeStringPattern) || matches.size() < 2)
  { // Pattern did not fully match or no match for capture group found
    return -1;
  }

  // 0 is the complete string that matched, 1 is the first capture group match
  std::string dateTimeString = matches[1];

  struct std::tm cDateTime;
  if (strptime(dateTimeString.c_str(), "%c", &cDateTime) == NULL)
  {
    //clientlogf("Failed to parse time string (input was \"%s\")!", dateTimeString.c_str());
    return -1;
  }

  return (int)timegm(&cDateTime);
}

/**
 * Extracts and returns the first Mapchange Message from a given ParsedDemo.
 *
 * @param ParsedDemo _parsedDemo The ParsedDemo to extract the first Mapchange Message from
 *
 * @return Mapchange The first Mapchange Message in the given ParsedDemo
 */
Mapchange* DemoMetaDataFinder::extractMapchangeMessageFromParsedDemo(ParsedDemo* _parsedDemo)
{
  Packet* nextPacket;
  do
  {
    nextPacket = _parsedDemo->getPacketStream()->getNextPacket();
    if (nextPacket)
    {
      Message* nextMessage;
      do
      {
        nextMessage = nextPacket->getMessageStream()->getNextMessage();
        if (nextMessage)
        {
          if (nextMessage->getType() == SV_MAPCHANGE)
          {
            Mapchange* mapchangeMessage = static_cast<Mapchange*>(nextMessage);
            return mapchangeMessage;
          }
        }
      }
      while (nextMessage);
    }
  }
  while (nextPacket);

  return NULL;
}
