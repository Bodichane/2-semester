#include "Matrix.h"
#include "gtest/gtest.h"

using namespace miit::algebra;

class MatrixTest : public ::testing::Test {
protected:
    // Setup code can go here, executed before each test.
    MatrixTest() {
        // Initialize objects here if needed.
    }

    ~MatrixTest() override {
        // Cleanup any resources here if needed.
    }

    // Objects declared here can be used by all tests in the test case.
};

// Test the default constructor.
TEST_F(MatrixTest, DefaultConstructor) {
    Matrix<int> m;
    EXPECT_EQ(m.getRows(), 0);
    EXPECT_EQ(m.getColumns(), 0);
}

// Test the parameterized constructor.
TEST_F(MatrixTest, ParameterizedConstructor) {
    Matrix<int> m(3, 4);
    EXPECT_EQ(m.getRows(), 3);
    EXPECT_EQ(m.getColumns(), 4);
}

// Test the copy constructor.
TEST_F(MatrixTest, CopyConstructor) {
    Matrix<int> m1(2, 2);
    Matrix<int> m2(m1);
    EXPECT_EQ(m2.getRows(), m1.getRows());
    EXPECT_EQ(m2.getColumns(), m1.getColumns());
}

// Test the move constructor.
TEST_F(MatrixTest, MoveConstructor) {
    Matrix<int> m1(2, 2);
    Matrix<int> m2(std::move(m1));
    EXPECT_EQ(m2.getRows(), 2);
    EXPECT_EQ(m2.getColumns(), 2);
}

// Test the toString() method.
TEST_F(MatrixTest, ToString) {
    Matrix<int> m(2, 2);
    std::string str = m.toString();
    // Check if the string representation is as expected.
}

// Test the element access operator().
TEST_F(MatrixTest, ElementAccess) {
    Matrix<int> m(2, 2);
    m(0, 0) = 1;
    EXPECT_EQ(m(0, 0), 1);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
