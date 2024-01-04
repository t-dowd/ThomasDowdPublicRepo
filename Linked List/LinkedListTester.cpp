#include <exception>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "gtest/gtest.h"
#include "LinkedList.h"

// Assuming the original code
// LinkedListTest.cpp

TEST(LinkedListTest, AppendAndSize) {
    LinkedList <int> GQ; // Change the object name from 'list' to 'GQ'
    EXPECT_TRUE(GQ.isEmpty());
    EXPECT_EQ(GQ.size(), 0);

    GQ.append(1);
    GQ.append(2);
    GQ.append(3);

    EXPECT_FALSE(GQ.isEmpty());
    EXPECT_EQ(GQ.size(), 3);
}

TEST(LinkedListTest, Remove) {
    // LinkedList GQ; // Change the object name from 'list' to 'GQ'
    LinkedList <int> GQ;
    GQ.append(1);
    GQ.append(2);
    GQ.append(3);

    GQ.remove(2);

    EXPECT_EQ(GQ.size(), 2);
    // EXPECT_EQ(GQ.toString(), "1->3");
}

TEST(LinkedListTest, RemoveNonExistent) {
    // LinkedList GQ; // Change the object name from 'list' to 'GQ'
    LinkedList <int> GQ;
    GQ.append(1);
    GQ.append(2);
    GQ.append(3);

    GQ.remove(4);

    EXPECT_EQ(GQ.size(), 3);
    // EXPECT_EQ(GQ.toString(), "1->2->3");
}
// Add more test cases as needed

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}