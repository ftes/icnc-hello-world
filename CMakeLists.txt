cmake_minimum_required(VERSION 3.2)
project(cnc_hello_world)
set( CMAKE_VERBOSE_MAKEFILE on )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories("$ENV{CNCROOT}/include")
link_directories("$ENV{CNCROOT}/lib/intel64")
include_directories("$ENV{CNCROOT}/tbb42_20140122oss/include")
link_directories("$ENV{CNCROOT}/tbb42_20140122oss/lib/intel64/gcc4.4")

set(SOURCE_FILES
    hello-world.cpp
    hello-world.h)

add_executable(cnc_hello_world ${SOURCE_FILES})

target_link_libraries(cnc_hello_world cnc rt tbb tbbmalloc)