# VARIABLES
set(PROJECT_NAME_STR apt_assignment_2)
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)

###
# Install Dependencies
###
cmake_minimum_required(VERSION 3.14)
project(PROJECT_NAME_STR)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

###
# Test Configuration
###
enable_testing()

add_executable(
  ${PROJECT_TEST_NAME}
  Node.cpp
  Node_test.cpp
)
target_link_libraries(
  ${PROJECT_TEST_NAME}
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_TEST_NAME})