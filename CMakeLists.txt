cmake_minimum_required(VERSION 3.10)
project(QueueTest)

# Enable C++11 standard
set(CMAKE_CXX_STANDARD 11)

# Set paths for GTest
set(GTEST_ROOT "D:/BOSCH/googletest/install")  # Set this to the install directory, should be path to googletest/install
set(GTEST_INCLUDE_DIR "${GTEST_ROOT}/include")    # This should point to the include directory
set(GTEST_LIB_DIR "${GTEST_ROOT}/lib")            # Assuming you built it here

# Manually specify the GTest libraries
set(GTEST_LIBRARIES "${GTEST_LIB_DIR}/gtest.lib" "${GTEST_LIB_DIR}/gtest_main.lib")

# Include directories
include_directories(${GTEST_INCLUDE_DIR})           # Includes gtest headers
include_directories("D:/BOSCH/QueueTest")           # Include your project directory, ${PROJECT_SOURCE_DIR}

# Add the executable for the test
add_executable(runTests test_queue.cpp)

# Link the Google Test framework
target_link_libraries(runTests ${GTEST_LIBRARIES})
