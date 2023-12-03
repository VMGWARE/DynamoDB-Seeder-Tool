
/*!
 * DynamoDB Seeder Tool
 * https://vmgware.dev/
 *
 * Copyright (c) 2023 VMG Ware
 * MIT Licensed
 */

#ifndef SEEDER_TOOL_H
#define SEEDER_TOOL_H

// Includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

// Namespaces
using namespace std;
using namespace rapidjson;

// Global variables
extern bool debug;
extern string appDir;
extern string tempDir;

// Debug logging macro
#define DEBUG_LOG(msg)                                   \
    do                                                   \
    {                                                    \
        if (debug)                                       \
            std::cout << "[DEBUG] " << msg << std::endl; \
    } while (0)

// Print banner
void printBanner();
bool canAccessDynamoDB();
#endif