cmake_minimum_required(VERSION 3.19.3)

# specify the C++ standard

set(PROJECT_NAME dataset)
project(${PROJECT_NAME} VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES *)

# file(GLOB ACTIVATION_SRC_FILES ../activation/*.h)
# file(GLOB LOSS_SRC_FILES ../loss/*.h)
# file(GLOB_RECURSE SRC_FILES *)

add_executable(dataset_test test/main.cpp ${SRC_FILES} ${MATH_SRC_FILES})
#target_link_libraries(dnn_test gtest gtest_main)
