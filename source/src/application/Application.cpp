/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Application.h"
#include "Commands/FindBestScoreTimes.h"
#include "Commands/FindDemoMetaData.h"
#include "Commands/RemoveMessageTypes.h"


// Public Methods

/**
 * Runs the application.
 *
 * @param int _argc The raw argument count
 * @param char[][] _argv The raw argument values
 *
 * @return int The application exit status
 */
int Application::run(int _argc, char **_argv)
{
  // Create and configure the app
  CLI::App app{"Provides commands to process AssaultCube demo files"};

  std::string demoFilePath;
  CLI::App* findBestScoreTimesCommand = app.add_subcommand("findbestscoretimes", "Finds the best score times per player name in a given demo and prints the results as a JSON string");
  findBestScoreTimesCommand->add_option("-d,--demo", demoFilePath, "The demo file to process")->required();
  findBestScoreTimesCommand->callback(
    [&demoFilePath]()
    {
      FindBestScoreTimes command;
      command.execute(demoFilePath);
    }
  );

  CLI::App* findDemoMetaDataCommand = app.add_subcommand("finddemometadata", "Finds the meta data for a given demo and prints the results as a JSON string");
  findDemoMetaDataCommand->add_option("-d,--demo", demoFilePath, "The demo file to process")->required();
  findDemoMetaDataCommand->callback(
    [&demoFilePath]()
    {
      FindDemoMetaData command;
      command.execute(demoFilePath);
    }
  );

  std::string outputFilePath;
  std::vector<std::string> messageTypesToRemove;
  CLI::App* removeMessageTypesCommand = app.add_subcommand("removemessagetypes", "Parses a given demo, filters out given message types and writes the result to a given path");
  removeMessageTypesCommand->add_option("-d,--demo", demoFilePath, "The demo file to process")->required();
  removeMessageTypesCommand->add_option("-o, --output", outputFilePath, "The output file path")->required();
  removeMessageTypesCommand->add_option("-t, --types", messageTypesToRemove, "The message types to remove")->required();
  removeMessageTypesCommand->callback(
    [&demoFilePath, &outputFilePath, &messageTypesToRemove]()
    {
      RemoveMessageTypes command;
      command.execute(demoFilePath, outputFilePath, messageTypesToRemove);
    }
  );

  app.require_subcommand();


  // Parse the raw input arguments and call the callback of the selected command
  CLI11_PARSE(app, _argc, _argv);

  return EXIT_SUCCESS;
}
