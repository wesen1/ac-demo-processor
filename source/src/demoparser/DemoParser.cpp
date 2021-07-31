/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "DemoParser.h"
#include "MessageStream/MessageParser.h"
#include "PacketStream/PacketStream.h"
#include "PacketStream/PacketParser.h"


// Public Methods

/**
 * Parses a given demo file.
 *
 * @param char[] _demoFilePath The path to the demo file to parse
 *
 * @return ParsedDemo The parsed demo data
 */
ParsedDemo* DemoParser::parseDemo(char* _demoFilePath)
{
  // Open the demo file
  const char* demoFilePath = path(_demoFilePath);
  stream* demoData = opengzfile(demoFilePath, "rb");
  if (!demoData)
  { // File could not be opened
    clientlogf("Failed to open file %s", demoFilePath);
    return NULL;
  }

  // Parse the demo header
  demoheader* demoHeader = parseDemoHeader(demoData);
  if (!demoHeader || !validateDemoHeader(demoHeader))
  {
    return NULL;
  }

  // Create the result
  return new ParsedDemo(
    demoHeader,
    new PacketStream(
      new PacketParser(
        new MessageParser(demoHeader->protocol)
      ),
      demoData
    )
  );
}


// Private Methods

/**
 * Extracts the demo header information from a given stream.
 *
 * @param stream _demoData The demo data stream to extract the header information from
 *
 * @return demoheader The extracted demo header
 */
demoheader* DemoParser::parseDemoHeader(stream* _demoData)
{
  demoheader* demoHeader = new struct demoheader();

  int numberOfReadBytes = _demoData->read(demoHeader, sizeof(demoheader));
  if (numberOfReadBytes != sizeof(demoheader) ||
      memcmp(demoHeader->magic, DEMO_MAGIC, sizeof(demoHeader->magic)))
  { // Invalid demo header
    clientlogf("Invalid demo header");
    return NULL;
  }
  else
  {
    lilswap(&demoHeader->version, 1);
    lilswap(&demoHeader->protocol, 1);

    return demoHeader;
  }
}

/**
 * Validates a given demo header.
 *
 * @param demoheader _demoHeader The demo header to validate
 *
 * @return bool True if the demo header is valid, false otherwise
 */
bool DemoParser::validateDemoHeader(demoheader* _demoHeader)
{
  if (_demoHeader->version != DEMO_VERSION)
  { // incompatible demo version
    clientlogf("Incompatible demo version");
    return false;
  }
  else if(_demoHeader->protocol != PROTOCOL_VERSION &&
          !(_demoHeader->protocol < 0 && _demoHeader->protocol == -PROTOCOL_VERSION) &&
          _demoHeader->protocol != 1132)
  { // incompatible protocol version
    clientlogf("Incompatible protocol version");
    return false;
  }
  else
  {
    return true;
  }
}
