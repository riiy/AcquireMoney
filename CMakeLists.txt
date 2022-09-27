cmake_minimum_required(VERSION 3.23)
# Set required C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
## Project
set(PROJECT_NAME
  AcquireMoney
)

project(${PROJECT_NAME}
  LANGUAGES CXX)

if (NOT CMAKE_BUILD_TYPE)
   set (CMAKE_BUILD_TYPE "RelWithDebInfo")
   message (
      STATUS "No CMAKE_BUILD_TYPE selected, defaulting to ${CMAKE_BUILD_TYPE}"
   )
endif ()


set(SOURCE_DIR
    src
)
set(SOURCE
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/get_stock_list.cpp
    ${SOURCE_DIR}/get_stock_his.cpp
)


## Third Lib
### Boost
find_package(Boost COMPONENTS program_options REQUIRED)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost Not found")
endif()
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

### Threads
find_package(Threads REQUIRED)
#
### PostgreSQL
# find_package(PostgreSQL REQUIRED)
### cpr http_client
find_package(cpr REQUIRED)

### json
include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::program_options cpr::cpr nlohmann_json::nlohmann_json)

## Test
enable_testing()
add_subdirectory(tests)
