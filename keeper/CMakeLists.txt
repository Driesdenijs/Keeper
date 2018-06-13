cmake_minimum_required (VERSION 2.6)

   
# The version number.
set (APPLICATION_VERSION_MAJOR 1)
set (APPLICATION_VERSION_MINOR 0)
set(APPLICATION_VERSION "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}")
 
# enable c language
enable_language(C)

#set(CMAKE_VERBOSE_MAKEFILE OFF)
 
# detect operating system
message(STATUS "Starting to build ${APPLICATION_VERSION}")
# detect host processor
message(STATUS "The host processor is ${CMAKE_HOST_SYSTEM_PROCESSOR}")
 
# recursive gather all the files in the header and source folder
file(GLOB_RECURSE ALL_SRC
    "include/*.h"
    "src/*.c"
)
message(STATUS "${ALL_SRC}") 
 
# example how to set c++ compiler flags for GNU
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_C_FLAGS__         "-O3 -Wall -Og -pthread")
    set(CMAKE_C_FLAGS           "-O0 -g3 -pthread")
    set(CMAKE_C_FLAGS_RELEASE   "-O3 -pthread")
endif()

include_directories("/usr/local/include") 
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/src")
 
 
# add the binary tree to the search path for include files
# so that we will find versions.h
include_directories("${PROJECT_BINARY_DIR}/include")
#include_directories("${PROJECT_BINARY_DIR}/source")
 
# add the executable
add_executable(keeper ${ALL_SRC})	
target_link_libraries(keeper "libfreefare.so")
target_link_libraries(keeper "libnfc.so")
target_link_libraries(keeper "wiringPi")
target_link_libraries(keeper "wiringPiDev")

