
/*!
 * DynamoDB Seeder Tool
 * https://vmgware.dev/
 *
 * Copyright (c) 2023 VMG Ware
 * MIT Licensed
 */

// Includes
#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <cstdlib>
#include <unistd.h> // For getting the current working directory
#include <getopt.h> // For command-line option parsing
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>        // Use istreamwrapper to read from ifstream
#include "spdlog/spdlog.h"                   // For logging
#include "spdlog/sinks/stdout_color_sinks.h" // For logging
#include "spdlog/sinks/basic_file_sink.h"    // Include for file logging
#include "utils/SeederTool.h"                // SeederTool Utility
// TODO: Include AWS SDK for C++ (DynamoDB)

// Namespaces
using namespace std;
using namespace rapidjson;

// Main function
int main(int argc, char *argv[])
{
    // Parse command-line options
    const char *const short_opts = "hp:d";
    const option long_opts[] = {
        {"help", no_argument, nullptr, 'h'},
        {"path", required_argument, nullptr, 'p'},
        {"debug", no_argument, nullptr, 'd'}, // Add debug option
    };

    string jsonDir;

    // Print banner
    printBanner();

    // Set application directory to AppData on Windows, home directory on Linux
#ifdef _WIN32
    appDir = getenv("APPDATA") + string("\\DynamoDB-Seeder-Tool");

    // Create app directory if it doesn't exist
    if (system(("if not exist \"" + appDir + "\" mkdir \"" + appDir + "\" > NUL 2>&1").c_str()) != 0)
    {
        cerr << "Error: Unable to create application directory." << endl;
        spdlog::get("file_logger")->error("Unable to create application directory.");
        return 1;
    }

    tempDir = appDir + string("\\temp");

    // Create temp directory if it doesn't exist
    if (system(("if not exist \"" + tempDir + "\" mkdir \"" + tempDir + "\" > NUL 2>&1").c_str()) != 0)
    {
        cerr << "Error: Unable to create temporary directory." << endl;
        spdlog::get("file_logger")->error("Unable to create temporary directory.");
        return 1;
    }
#else
    appDir = getenv("HOME") + string("/.DynamoDB-Seeder-Tool");
    tempDir = appDir + string("/temp");
#endif

    // Initialize logger
    try
    {
        // Set the log pattern and create loggers
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");

        auto console_logger = spdlog::stdout_color_mt("console");
        auto file_logger = spdlog::basic_logger_mt("file_logger", appDir + string("/log.txt"));

        // If debug flag is specified in the command arguments, set log level to debug
        spdlog::set_level(spdlog::level::debug);
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cerr << "Log initialization failed: " << ex.what() << std::endl;
        return 1;
    }

    // Parse command-line options
    int opt;
    while ((opt = getopt_long(argc, argv, short_opts, long_opts, nullptr)) != -1)
    {
        switch (opt)
        {
        case 'h':
            // Print usage
            cout << "Usage: " << argv[0] << " [OPTIONS]" << endl;
            cout << "Description: This tool is used to seed DynamoDB tables with data from JSON files." << endl;
            cout << "Options:" << endl;
            cout << "  -h, --help         Show this help message and exit." << endl;
            cout << "  -p, --path         Specify the path to JSON directory." << endl;
            cout << "  -d, --debug        Enable debug logging." << endl;
            return 0;

        case 'p':
            jsonDir = optarg;
            break;

        case 'd':
            debug = true;
            break;

        default:
            cerr << "Usage: " << argv[0] << " [OPTIONS]" << endl;
            return 1;
        }
    }

    DEBUG_LOG("Starting program.");
    spdlog::get("file_logger")->debug("Starting program.");

    // Check if path is empty
    if (jsonDir.empty())
    {
        cerr << "Error: JSON directory path is required. Please specify with -p or --path." << endl;
        return 1;
    }

    // Handle case where path is "./" or "."
    if (jsonDir == "./" || jsonDir == ".")
    {
        char currentPath[FILENAME_MAX];
        if (getcwd(currentPath, sizeof(currentPath)) != nullptr)
        {
            jsonDir = currentPath;
        }
    }

    // Check if DynamoDB is running
    if (!canAccessDynamoDB())
    {
        cerr << "Error: Unable to access DynamoDB." << endl;
        spdlog::get("file_logger")->error("Unable to access DynamoDB.");
        return 1;
    }

    // Make sure the required parameters are passed in
    // If not we can print the help menu and exit

    // If the required parameters are passed in
    // Check if the folder passed exists, if not throw an exception

    // Return
    return 0;
}