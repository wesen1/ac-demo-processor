/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "demometadatafinder/DemoMetaDataFinder.h"
#include "../../demometadatafinder/DemoMetaData.h"
#include "cjson/cJSON.h"

#ifndef COMMAND_FIND_DEMO_META_DATA
#define COMMAND_FIND_DEMO_META_DATA

class FindDemoMetaData
{
  public:
    void execute(std::string);

  private:
    cJSON* generateJson(DemoMetaData*);
};

#endif
