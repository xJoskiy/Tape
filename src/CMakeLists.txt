CMAKE_MINIMUM_REQUIRED(VERSION 3.27)

file(GLOB_RECURSE lib_sources "*.cpp" "*.h")
list(REMOVE_ITEM lib_sources ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_library(${project_name} ${lib_sources})

set(BINARY ${project_name}_run)

add_executable(${BINARY} main.cpp ${lib_sources})
    