#ifndef HEADER_POINT
#define HEADER_POINT
#include <iostream>

class Point
{
	public:
	 	/**
	     	* Point constructor with default x and y values of 0.
	     	* @param x The x coordinate of the point.
	     	* @param y The y coordinate of the point.
		* @throws std::invalid_argument when x and y is negative.
	     	*/
		Point(int x = 0, int y = 0);
		
	private:
		int x;
		int y;
	
	auto operator<=>(const Point&) const = default;
};

#endif

