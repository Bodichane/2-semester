#include <iostream>
#include <memory>
#include "Form.h"
#include "Circle.h"
#include "Point.h"

int main() 
{
    std::unique_ptr<Point> center = std::make_unique<Point>(2, 3);
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(5, *center);
    std::cout << circle->ToString() << std::endl;

    return 0;
}
