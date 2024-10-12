cmake_minimum_required(VERSION 3.10)
project(QueueTest)

# Enable C++11 standard
set(CMAKE_CXX_STANDARD 11)

# Set paths for GTest
set(GTEST_ROOT "D:/BOSCH/googletest/googletest")  # Use the directory where the gtest folder is located
set(GTEST_INCLUDE_DIR "${GTEST_ROOT}/include")    # This should point to the include directory
set(GTEST_LIB_DIR "${GTEST_ROOT}/build/lib/Release")  # Assuming you built it here

# Manually specify the GTest libraries
set(GTEST_LIBRARIES "${GTEST_LIB_DIR}/gtest.lib" "${GTEST_LIB_DIR}/gtest_main.lib")

# Include directories
include_directories(${GTEST_INCLUDE_DIR})           # Includes gtest headers
include_directories(${PROJECT_SOURCE_DIR})           # Include your project directory

# Add the executable for the test
add_executable(runTests test_queue.cpp)

# Link the Google Test framework
target_link_libraries(runTests ${GTEST_LIBRARIES})
