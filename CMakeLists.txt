cmake_minimum_required(VERSION 3.5)
project(DynamoDB-Seeder-Tool)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Collect all source files in src and src/utils
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/utils/*.cpp")

add_executable(dynamo-seeder ${SOURCES})

# Add the path to the rapidjson headers
target_include_directories(dynamo-seeder PRIVATE ${CMAKE_SOURCE_DIR}/include)