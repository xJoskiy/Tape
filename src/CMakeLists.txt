CMAKE_MINIMUM_REQUIRED(VERSION 3.27)

file(GLOB_RECURSE sources "*.cpp" "*.h")

set(BINARY ${project_name}_run)

add_executable(${BINARY} ${sources})

add_custom_command(TARGET ${BINARY} 
    POST_BUILD
    COMMAND rm -rf ../tmp/**
)
