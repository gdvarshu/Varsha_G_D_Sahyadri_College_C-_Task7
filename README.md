# Varsha_G_D_Sahyadri_College_C++_Task7
C++ TASK 7:
Task: Implementing a Distributed Database Connector with Poco C++ Libraries
Summary:
In this task, you will take on the challenge of designing and implementing a C++ connector library using Poco C++ libraries. 
The library will facilitate applications in connecting and interacting with Yugabyte, a distributed database, offering efficient data retrieval and storage capabilities.

Requirements:
To build and run this project successfully, ensure the following tools are installed and configured:

-Visual Studio 2022
- MinGW-w64 (g++)
- CMake
- vcpkg (for Poco installation)

Install Poco via vcpkg
 Framework Requirements:
- Remote Method Invocation
- TCP-based communication using Poco::Net
- JSON message parsing using Poco::JSON
- Dispatching function calls based on method names
- Client-Server architecture

 How to Build
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE="C:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build . --config Release

How to Run
.\connector.exe


  
