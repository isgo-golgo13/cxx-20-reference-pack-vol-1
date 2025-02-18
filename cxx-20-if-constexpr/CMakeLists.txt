cmake_minimum_required(VERSION 3.20)

# Project definition
project(Cpp20Project-1 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include FetchContent module
include(FetchContent)

# Fetch fmt library
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.1.1 # Replace with the latest stable version if needed
)
FetchContent_MakeAvailable(fmt)

# Collect all source files in the project directory, excluding CMake-generated files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.hpp"
)
list(FILTER SOURCES EXCLUDE REGEX ".*/CMakeFiles/.*")

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Link fmt library to the target
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

# Optionally include directories (if needed for headers)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})
