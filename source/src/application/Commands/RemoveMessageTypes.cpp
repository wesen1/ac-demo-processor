/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "RemoveMessageTypes.h"
#include "../../demoparser/DemoParser.h"
#include "../../demoparser/ParsedDemo.h"
#include "../../demowriter/DemoWriter.h"
#include <fstream>


// Public Methods

/**
 * Parses a given demo, filters out given message types and writes the result to a given path.
 *
 * @param std::string _demoFilePath The path to the demo file to parse
 * @param std::string _outputFilePath The path to write the resulting demo to
 * @param std::vector<std::string> _messageTypesToRemove The names of the message types to remove from the demo
 */
void RemoveMessageTypes::execute(std::string _demoFilePath, std::string _outputFilePath, std::vector<std::string> _messageTypesToRemove)
{
  clientlogf("Demo: %s", _demoFilePath.c_str());
  clientlogf("Output: %s", _outputFilePath.c_str());
  clientlogf("Message types to remove:");
  for (std::string messageType : _messageTypesToRemove)
  {
    clientlogf("- %s", messageType.c_str());
  }

  DemoWriter* demoWriter = new DemoWriter(_messageTypesToRemove);

  // Parse the input demo
  DemoParser* demoParser = new DemoParser();
  ParsedDemo* parsedDemo = demoParser->parseDemo(strdup(_demoFilePath.c_str()));

  // Create the output file if it does not exist yet
  std::ofstream output(_outputFilePath);

  // Write the demo to the output file
  stream* outputFile = opengzfile(_outputFilePath.c_str(), "wb");
  demoWriter->writeDemo(outputFile, parsedDemo);
  outputFile->close();
}
