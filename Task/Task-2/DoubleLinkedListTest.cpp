#include "doubleLinkedList.h"
#include <gtest/gtest.h>

class DoubleLinkedListTest : public ::testing::Test {
protected:
    DoubleLinkedList list;
};

TEST_F(DoubleLinkedListTest, IsEmptyOnConstruction) {
    EXPECT_TRUE(list.empty());
}

TEST_F(DoubleLinkedListTest, SizeIsZeroOnConstruction) {
    EXPECT_EQ(0, list.length());
}

TEST_F(DoubleLinkedListTest, PushBackAddsElement) {
    list.push_back(5);
    EXPECT_EQ(5, list[0]);
    EXPECT_EQ(1, list.length());
}

TEST_F(DoubleLinkedListTest, PushFrontAddsElement) {
    list.push_front(10);
    EXPECT_EQ(10, list[0]);
    EXPECT_EQ(1, list.length());
}

TEST_F(DoubleLinkedListTest, PopBackRemovesElement) {
    list.push_back(20);
    list.push_back(30);
    list.pop_back();
    EXPECT_EQ(1, list.length());
}

TEST_F(DoubleLinkedListTest, PopFrontRemovesElement) {
    list.push_front(40);
    list.push_front(50);
    list.pop_front();
    EXPECT_EQ(1, list.length());
}

TEST_F(DoubleLinkedListTest, RemoveElementAtIndex) {
    list.push_back(60);
    list.push_back(70);
    list.push_back(80);
    list.remove(1); // Removes 70
    EXPECT_EQ(2, list.length());
    EXPECT_EQ(80, list[1]);
}

// ... d'autres tests pour les constructeurs de copie, l'opérateur d'affectation, etc.

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
