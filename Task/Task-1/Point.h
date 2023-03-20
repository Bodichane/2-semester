#ifndef HEADER_POINT
#define HEADER_POINT
#include <iostream>

class Point
{
	public:
		Point();
		Point(unsigned int x, unsigned int y);
		
	private:
		unsigned int x;
		unsigned int y;

	friend std::ostream& operator<<(std::ostream& os, Point const& p);
	friend std::istream& operator>>(std::istream& is, Point& p);
	friend bool operator==(const Point& lhs, const Point& rhs);
	friend bool operator!=(const Point& lhs, const Point& rhs);
	friend Point operator+(const Point& lhs, const Point& rhs);
	friend Point operator-(const Point& lhs, const Point& rhs);
	friend Point operator+(const Point& lhs, const unsigned int& rhs);
	friend Point operator-(const Point& lhs, const unsigned int& rhs);
};

#endif

