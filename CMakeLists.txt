cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_COMPILER "clang++-15")
set(CMAKE_C_COMPILER "clang-15")
# Set required C++ standard
#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
SET (CMAKE_C_FLAGS_INIT                "-Wall -std=c99")
SET (CMAKE_C_FLAGS_DEBUG_INIT          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE_INIT        "-O3 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")

SET (CMAKE_CXX_FLAGS_INIT                "-Wall")
SET (CMAKE_CXX_FLAGS_DEBUG_INIT          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE_INIT        "-O3 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++20")
set(CMAKE_EXE_LINKER_FLAGS "-lc++abi")
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
find_package(PostgreSQL REQUIRED)
add_executable(${PROJECT_NAME} ${SOURCE})
#
target_link_libraries(${PROJECT_NAME} Boost::program_options PostgreSQL::PostgreSQL)
#add_subdirectory(tests)
