// Widh Jio
// main.core.cpp

#include "core.hpp"

using std::atexit;
using std::endl;
using std::size_t;
using std::string;
using namespace core;

int main(int argc, char **argv)
{
  std::cout.setf(std::ios::unitbuf);

  $info << "Initializing " << bold << "15na" << def << " AP program..." << endl;

  atexit(_terminate);

  // Analyzing arguments
  bool isModelSelected = false;
  for (int i = 1; i < argc; i++)
  {
    string arg = c2str(argv[i]);

    if (arg.find("-") == 0)
    {
      // Options
      bool isFullArg = arg.find("--") == 0;
      arg = arg.substr(isFullArg ? 2 : 1);
      size_t divPosition = arg.find("=");
      if (divPosition == string::npos)
      {
        // Flag option
        (isFullArg ? procFlagOption : procShortFlagOption)(arg);
      }
      else
      {
        // Data option
        string name = arg.substr(0, divPosition);
        string value = arg.substr(divPosition + 1);
        (isFullArg ? procDataOption : procShortDataOption)(name, value);
      }
    }
    else
    {
      $warn << "Ignored argument: " << arg << endl;
    }
  }

  $success << "Checked arguments" << endl;

  // Start websocket server
  ws::init();

  // Open linux connector socket
  csi::openSocket();

  return 0;
}
