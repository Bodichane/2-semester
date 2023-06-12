#include "gtest/gtest.h" 
#include "Point.h" 

// Define a fixture class for Point tests
class PointTest : public ::testing::Test
{
    protected:
       Point p1;  

       void SetUp() override
       {
           p1 = Point(2, 3);  
       }
};

// Test the output stream operator
TEST_F(PointTest, OutputStreamOperator)
{
    std::stringstream ss;
    ss << p1;

    ASSERT_EQ(ss.str(), "(2, 3)");
}

// Test the comparison operator
TEST_F(PointTest, ComparisonOperator)
    Point p2(2, 3);

    ASSERT_EQ(p1, p2);
}

// Run the tests
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
