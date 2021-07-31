/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Application.h"


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

  // Parse the raw input arguments and call the callback of the selected command
  CLI11_PARSE(app, _argc, _argv);

  return EXIT_SUCCESS;
}
