#include "Circle.h"

Circle::Circle() : radius(0) {}

Circle::Circle(unsigned int radius, const Point& center) : radius(radius), center(center) {}

std::string Circle::ToString() const
{
    std::stringstream ss;
    ss << "Circle: radius=" << radius << " center=" << center;
    return ss.str();
}

void Circle::FromString(const std::string& str)
{
    std::stringstream ss(str);
    std::string dummy;
    ss >> dummy >> dummy >> radius >> dummy >> center;
}

bool Circle::Validate(unsigned int radius) 
{
    return radius > 0;
}

void Circle::ValidateAndThrow(unsigned int radius) 
{
    if (!Validate(radius)) {
        throw std::invalid_argument("Invalid circle radius");
    }
}
