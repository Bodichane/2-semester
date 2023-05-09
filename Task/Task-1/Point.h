#ifndef HEADER_POINT
#define HEADER_POINT
#include <iostream>

class Point
{
	private:
		int x;
		int y;
	public:
	 	/**
	     	* Point constructor with default x and y values of 0.
	     	* @param x The x coordinate of the point.
	     	* @param y The y coordinate of the point.
		* @throws std::invalid_argument when x and y is negative.
	     	*/
		Point(int x = 0, int y = 0);
		/**
		* Overloading of the output stream operator << to print a point.
		* @param os The output stream.
		* @param p The point to be printed.
		* @return The output stream.
		*/
		friend std::ostream& operator<<(std::ostream& os, const Point& p);
	
		auto operator<=>(const Point&) const = default;
};

#endif

