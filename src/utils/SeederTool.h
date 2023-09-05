
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

// Namespaces
using namespace std;

// Global variables
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
#endif