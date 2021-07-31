/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "ParsedDemo.h"
#include "cube.h"

#ifndef DEMO_PARSER
#define DEMO_PARSER

class DemoParser
{
  private:
    demoheader* parseDemoHeader(stream*);
    bool validateDemoHeader(demoheader*);

  public:
    ParsedDemo* parseDemo(char*);
};

#endif
