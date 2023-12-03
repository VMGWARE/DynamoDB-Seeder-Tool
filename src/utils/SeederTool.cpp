
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
bool debug = false;
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
    cout << "Please ensure you have the AWS CLI configured and accessible.\n";
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

// Get the table name from a JSON file
string getTableNameFromJson(const string &jsonFilePath)
{
    DEBUG_LOG("Getting table name from JSON: " << jsonFilePath);

    ifstream file(jsonFilePath);
    if (file.is_open())
    {
        // Parse JSON using rapidjson
        IStreamWrapper inputStream(file);

        Document root;
        root.ParseStream(inputStream);

        if (!root.HasParseError() && root.HasMember("TableName") && root["TableName"].IsString())
        {
            string tableName = root["TableName"].GetString();
            DEBUG_LOG("Extracted table name: " << tableName);
            return tableName;
        }
    }

    DEBUG_LOG("Table name extraction failed.");
    return "";
}

// Check if DynamoDB can be accessed
bool canAccessDynamoDB()
{
    DEBUG_LOG("Checking if DynamoDB can be accessed.");

    // Use the AWS CLI to describe the table and check if it exists
    string command = "aws dynamodb list-tables --output json > NUL 2>&1";
    int result = system(command.c_str());
    return result == 0;
}