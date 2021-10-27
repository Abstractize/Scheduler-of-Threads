cmake_minimum_required(VERSION 3.16.3)
project(Client VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB SOURCES 
    src/*.c 
    src/*.h 
    src/**/*.h 
    src/**/*.c
    src/**/**/*.h 
    src/**/**/*.c
)

add_executable(Client ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${PROJECT_NAME} curl pthread jansson)