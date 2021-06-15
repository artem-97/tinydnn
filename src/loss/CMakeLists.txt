cmake_minimum_required(VERSION 3.19.3)

# specify the C++ standard
set(PROJECT_NAME loss)
project(${PROJECT_NAME} VERSION 0.1.0)

# include_directories(test)
# include_directories(src)
file(GLOB SRC_FILES *)
file(GLOB TEST_FILES test/*.cpp)
# add_subdirectory(test)
# add_subdirectory(src)

# add_library(${PROJECT_NAME} ${SRC_FILES} )

add_executable(loss_test test/main.cpp ${SRC_FILES})
target_link_libraries(loss_test gtest gtest_main )
