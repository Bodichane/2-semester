#include <gtest/gtest.h>
#include "DoubleLinkedList.h"

// Test fixture for the DoubleLinkedList class
class DoubleLinkedListTest : public ::testing::Test {
protected:
    // Create a linked list object before each test
    void SetUp() override {
        list = DoubleLinkedList<int>();
    }

    DoubleLinkedList<int> list;
};

// Test the empty() function
TEST_F(DoubleLinkedListTest, Empty) {
    // Verify that the list is initially empty
    EXPECT_TRUE(list.empty());

    // Add an element to the list
    list.push_back(42);

    // Verify that the list is not empty after adding an element
    EXPECT_FALSE(list.empty());
}

// Test the length() function
TEST_F(DoubleLinkedListTest, Length) {
    // Verify that the initial length of the list is zero
    EXPECT_EQ(list.length(), 0);

    // Add elements to the list
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Verify that the length of the list is updated correctly
    EXPECT_EQ(list.length(), 3);
}

// Test the push_front() function
TEST_F(DoubleLinkedListTest, PushFront) {
    // Add elements to the front of the list
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    // Verify that the elements are inserted in the correct order
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
}

// Test the push_back() function
TEST_F(DoubleLinkedListTest, PushBack) {
    // Add elements to the back of the list
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Verify that the elements are inserted in the correct order
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
}

// Test the operator[] function
TEST_F(DoubleLinkedListTest, OperatorIndex) {
    // Add elements to the list
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Verify that the operator[] returns the correct element at each index
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
}

// Test the remove() function
TEST_F(DoubleLinkedListTest, Remove) {
    // Add elements to the list
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Remove the element at index 1
    list.remove(1);

    // Verify that the element is removed and the list is updated correctly
    EXPECT_EQ(list.length(), 2);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 3);
}

// Test the to_string() function
TEST_F(DoubleLinkedListTest, ToString) {
    // Add elements to the list
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Verify that the string representation is correct
    std::string expected = "[1, 2, 3]";
    EXPECT_EQ(list.to_string(), expected);
}

// Test the stream insertion operator
TEST_F(DoubleLinkedListTest, StreamInsertion) {
    // Add elements to the list
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Create an output stringstream
    std::stringstream ss;

    // Insert the list into the stringstream
    ss << list;

    // Verify that the string representation is correct
    std::string expected = "[1, 2, 3]";
    EXPECT_EQ(ss.str(), expected);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
