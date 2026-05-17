cmake_minimum_required(VERSION 3.10)
project(mini_AMAZON)

set(CMAKE_CXX_STANDARD 17)

# Collect all source files
file(GLOB SOURCES "../source_files/*.cpp")
file(GLOB HEADERS "../header_files/*.h")

# Create executable
add_executable(mini_amazon ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(mini_amazon PRIVATE include)