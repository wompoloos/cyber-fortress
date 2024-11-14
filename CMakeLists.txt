# Minimum CMake version
cmake_minimum_required(VERSION 3.11)

# Require modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name
project(cyber-fortress-ver-1.0)

#### Setup Directories ####
# Source directory
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src/")
set(SOURCE_INCS "${PROJECT_SOURCE_DIR}/include/")

# Main output directory
set(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

# Ouput all DLLs from all libs into main build folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#### Add External Dependencies ####
add_subdirectory("lib/sfml")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

#### Cyber Fortress ####
# Source files
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp" "${SOURCE_INCS}/*.h")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the SFML libraries
target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCS})
target_link_libraries(${PROJECT_NAME} sfml-graphics)
