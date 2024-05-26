enable_testing()

file(GLOB_RECURSE sources "*.cpp")
set(BINARY ${project_name}_test)

add_executable(${BINARY} ${sources})
include_directories(../src)

target_link_libraries(${BINARY} gtest_main ${project_name} gmock)

add_test(NAME ${BINARY} COMMAND ${BINARY})
