CMAKE_MINIMUM_REQUIRED(VERSION 3.27)

set(project_name tape)

set(CMAKE_COMMPILE_WARNING_AS_ERROR ON)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_STANDARD 20)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif (NOT CMAKE_BUILD_TYPE)

add_subdirectory(lib/googletest)
add_subdirectory(src)
add_subdirectory(tests)