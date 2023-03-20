#include "Point.h"

Point::Point() : x(0), y(0)
{

}

Point::Point(unsigned int, unsigned int y) : x(x), y(y)
{

}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) 
{
    is >> p.x >> p.y;
    return is;
}

bool operator==(const Point& lhs, const Point& rhs) 
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

bool operator!=(const Point& lhs, const Point& rhs) 
{
    return !(lhs == rhs);
}

Point operator+(const Point& lhs, const Point& rhs) 
{
    return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

Point operator-(const Point& lhs, const Point& rhs) 
{
    return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

Point operator+(const Point& lhs, const unsigned int& rhs) 
{
    return Point(lhs.x + rhs, lhs.y + rhs);
}

Point operator-(const Point& lhs, const unsigned int& rhs) 
{
    return Point(lhs.x - rhs, lhs.y - rhs);
}
