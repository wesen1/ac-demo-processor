/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "DemoMetaData.h"
#include "../demoparser/ParsedDemo.h"
#include "../demoparser/MessageStream/Messages/Mapchange.h"

#ifndef DEMO_META_DATA_FINDER
#define DEMO_META_DATA_FINDER

class DemoMetaDataFinder
{
  private:
    int extractTimestampFromDemoHeader(demoheader*);
    Mapchange* extractMapchangeMessageFromParsedDemo(ParsedDemo*);

  public:
    DemoMetaData* findDemoMetaData(ParsedDemo*);
};

#endif
