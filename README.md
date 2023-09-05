# DynamoDB Seeder Tool

The **DynamoDB Seeder Tool** is a command line tool that allows you to seed your DynamoDB tables with data from a JSON file. It is written in C++ and uses the AWS SDK for C++.

## Overview

- Seeding your DynamoDB tables with data is a common task when developing applications that use DynamoDB.
- Written in C++.
- Uses the AWS SDK for C++.
- Uses the DynamoDB Local service.
- Designed to accelerate local development and testing workflows.
- Cross-platform C++ application using the CMake build system.

## Prerequisites

- [CMake](https://cmake.org/)
- AWS SDK for C++
- [DynamoDB Local](https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/DynamoDBLocal.html)

## Usage

1. Clone this repository to your local machine:

   ```
   git clone https://github.com/VMGWARE/DynamoDB-Seeder-Tool.git
   ```

2. Navigate to the cloned repository:

   ```
   cd DynamoDB-Seeder-Tool
   ```

3. Build the C++ application using CMake:

   - For Linux/MacOS, use the CMake command-line tools:

     ```
     mkdir build
     cd build
     cmake ..
     make
     ```

   - For Windows, use the CMake GUI or CLion to build the project. Alternatively, you can use the CMake command-line tools:

     ```
     mkdir build
     cd build
     cmake ..
     cmake --build .
     ```

## License

This project is licensed under the MIT License. For more details, see the [LICENSE](LICENSE) file.

## Contributions

Contributions are welcome! If you encounter any issues or have improvements to suggest, feel free to open an issue or submit a pull request.

## Contact

For any questions or suggestions, please feel free to [contact the author](mailto:developers@vmgware.dev). You can also find more information about the author below.

---

By [VMG Ware](https://github.com/VMGWARE)
