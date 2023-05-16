#include <cassert>
#include <stdexcept>
#include "Point.h"
#include "Circle.h"

void TestPoint() {
    // Test valid point
    Point p1(2, 3);
    assert(p1 << "(2,3)");

    // Test invalid point
    try {
        Point p2(-2, -3);
        assert(false && "Expected exception");
    }
    catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Invalid circle point.");
    }
}

void TestCircle() {
    // Test valid circle
    Point center1(2, 3);
    Circle c1(5, center1);
    assert(c1.ToString() == "Circle: radius=5 center=(2,3)");

    // Test invalid radius
    try {
        Point center2(2, 3);
        Circle c2(-5, center2);
        assert(false && "Expected exception");
    }
    catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Invalid circle radius.");
    }
}

int main() {
    TestPoint();
    TestCircle();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
