#include <gtest/gtest.h>
#include "Circle.h"

// Test fixture for the Circle class
class CircleTest : public ::testing::Test {
    protected:
        void SetUp() override {
            circle = Circle(5, Point(2, 3));
        }

    Circle circle;
};

// Test the default constructor
TEST_F(CircleTest, DefaultConstructor) {
    Circle defaultCircle;

    EXPECT_EQ(defaultCircle.radius, 0);
    EXPECT_EQ(defaultCircle.center.x, 0);
    EXPECT_EQ(defaultCircle.center.y, 0);
}

// Test the parameterized constructor
TEST_F(CircleTest, ParameterizedConstructor) {
    EXPECT_EQ(circle.radius, 5);
    EXPECT_EQ(circle.center.x, 2);
    EXPECT_EQ(circle.center.y, 3);
}

// Test the ToString() function
TEST_F(CircleTest, ToString) {
    std::string expected = "Circle with radius: 5, center: (2, 3)";
    EXPECT_EQ(circle.ToString(), expected);
}
