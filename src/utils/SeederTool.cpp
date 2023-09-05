
/*!
 * DynamoDB Seeder Tool
 * https://vmgware.dev/
 *
 * Copyright (c) 2023 VMG Ware
 * MIT Licensed
 */

#include "SeederTool.h"

// Variables
string appDir;
string tempDir;

// Print banner
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