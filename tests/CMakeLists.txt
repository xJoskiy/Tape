enable_testing()

file(GLOB_RECURSE sources "*.cpp")
set(BINARY ${project_name}_test)

add_executable(${BINARY} ${sources})
include_directories(../src)

target_link_libraries(${BINARY} ${project_name} gtest_main gmock)

add_test(NAME ${BINARY} COMMAND ${BINARY})
