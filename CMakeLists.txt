CMAKE_MINIMUM_REQUIRED(VERSION 3.27)

set(CMAKE_COMMPILE_WARNING_AS_ERROR ON)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_STANDARD 14)
set(project_name tape)

add_subdirectory(lib/googletest)
add_subdirectory(src)
add_subdirectory(tests)