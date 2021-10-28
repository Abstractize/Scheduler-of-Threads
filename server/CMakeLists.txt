cmake_minimum_required(VERSION 3.16.3)
project(Server VERSION 0.1.0)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

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

ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

add_executable(Server ${SOURCES})

INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION}) 
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)
include(CPack)

target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES} ulfius jansson orcania yder pthread)