
/*!
 * DynamoDB Seeder Tool
 * https://vmgware.dev/
 *
 * Copyright (c) 2023 VMG Ware
 * MIT Licensed
 */

#include "SeederTool.h" // SeederTool Utility
#include <unistd.h>     // For getting the current working directory

// Variables
string appDir;
string tempDir;

/**
 * Display the banner
 */
void printBanner()
{
    cout << "#######################################\n";
    cout << "#                                     #\n";
    cout << "#        DynamoDB Seeder Tool         #\n";
    cout << "#                                     #\n";
    cout << "#######################################\n\n";
    cout << "This utility will help you seed your DynamoDB tables with data.\n";
    cout << "---------------------------------------\n\n";
}

/**
 * Helper function to get the current working directory
 *
 * @param path The path to check
 *
 * @return string The path
 */
string pathHelper(string path)
{
    // If the path is ./ or . or ../
    if (path == "./" || path == "." || path == "../")
    {
        char currentPath[FILENAME_MAX];
        if (getcwd(currentPath, sizeof(currentPath)) != nullptr)
        {
            return currentPath;
        }
        else
        {
            return "";
        }
    }
    // If the path is not ./ or . or ../
    else
    {
        // Return the path
        return path;
    }
}