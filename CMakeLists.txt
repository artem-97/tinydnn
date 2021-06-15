cmake_minimum_required(VERSION 3.19.3)

# specify the C++ standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic")
set(CMAKE_CXX_COMPILER "g++-10")
set(CMAKE_CXX_STANDARD 20)

# set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
# set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")


set(PROJECT_NAME tinyDNN)
project(${PROJECT_NAME} VERSION 0.1.0)

#include_directories(src)

#add_subdirectory(src/dataset)
add_subdirectory(src/loss)
#add_subdirectory(src/dnn)

file(GLOB_RECURSE SRC_FILES src/*)
add_executable(${PROJECT_NAME} ${SRC_FILES} )
# add_library(${PROJECT_NAME} ${SRC_FILES} )
