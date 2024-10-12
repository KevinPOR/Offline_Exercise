#include <gtest/gtest.h>
//#include "queue.h"
#include <thread>
#include <chrono>

class QueueTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Code for setting up before each test (if needed)
    }

    void TearDown() override {
        // Code for cleaning up after each test (if needed)
    }
};

// Test case for basic push and pop functionality
TEST_F(QueueTest, BasicPushPop) {
    Queue<int> q(2);
    q.Push(1);
    q.Push(2);
    EXPECT_EQ(q.Pop(), 1);
    EXPECT_EQ(q.Pop(), 2);
}

// Test case for queue overflow and element drop
TEST_F(QueueTest, OverflowDrop) {
    Queue<int> q(2);
    q.Push(1);
    q.Push(2);
    q.Push(3); // This should drop element 1
    EXPECT_EQ(q.Pop(), 2);
    EXPECT_EQ(q.Pop(), 3);
}

// Test case for pop with timeout
TEST_F(QueueTest, PopWithTimeout) {
    Queue<int> q(2);
    EXPECT_THROW(q.PopWithTimeout(100), std::runtime_error);
    q.Push(1);
    EXPECT_NO_THROW(q.PopWithTimeout(100));
}

// Test case for counting elements
TEST_F(QueueTest, CountElements) {
    Queue<int> q(3);
    EXPECT_EQ(q.Count(), 0);
    q.Push(1);
    EXPECT_EQ(q.Count(), 1);
    q.Push(2);
    EXPECT_EQ(q.Count(), 2);
    q.Pop();
    EXPECT_EQ(q.Count(), 1);
}

// Test case for queue size
TEST_F(QueueTest, QueueSize) {
    Queue<int> q(3);
    EXPECT_EQ(q.Size(), 3);
}

// Test case for blocking Pop and releasing when new element is pushed
TEST_F(QueueTest, BlockingPop) {
    Queue<int> q(2);
    std::thread reader([&q]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        EXPECT_EQ(q.Pop(), 5); // should be released after Push(5)
    });

    std::thread writer([&q]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        q.Push(5);
    });

    reader.join();
    writer.join();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
