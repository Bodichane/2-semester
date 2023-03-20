#include <iostream>
#include "Form.h"
#include "Circle.h"
#include "Point.h"

int main() 
{
    unsigned int max_x = 1920;
    unsigned int max_y = 1080;

    Circle::ValidateAndThrow(10);

    Circle c1(5, Point(10, 10));
    c1.Draw();

    Circle c2;
    c2.Read(std::cin);
    if (c2.radius > max_x || c2.radius > max_y) 
    {
        std::cout << "Invalid circle: radius too large" << std::endl;
    }
    else 
    {
        c2.Draw();
    }

    return 0;
}