#include <iostream>
#include "Form.h"
#include "Circle.h"
#include "Point.h"

int main() 
{
    Point center(2, 3);
    Circle circle(5, center);
    std::cout << circle.ToString() << std::endl;

    return 0;
}
