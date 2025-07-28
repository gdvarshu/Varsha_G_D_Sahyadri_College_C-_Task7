cmake_minimum_required(VERSION 3.10)
project(YugabyteConnector)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

# VCPKG integration
if(DEFINED ENV{VCPKG_ROOT})
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

find_package(Poco REQUIRED COMPONENTS Data DataODBC Foundation)

add_executable(connector src/main.cpp src/Connector.cpp)
target_link_libraries(connector PRIVATE Poco::Data Poco::DataODBC Poco::Foundation)
