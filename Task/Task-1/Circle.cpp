#include "Circle.h"

Circle::Circle() : radius(0) {}

Circle::Circle(unsigned int radius, const Point& center) : radius(radius), center(center) 
{
    if (radius > 0)
    {
        radius = radius;
    }
    else
    {
        throw std::invalid_argument("Invalid circle radius.");
    }
}

std::string Circle::ToString() const
{
    std::stringstream ss;
    ss << "Circle: radius=" << radius << " center=" << center;
    return ss.str();
}
