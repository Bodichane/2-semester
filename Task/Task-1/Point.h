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
	     	*/
		Point(unsigned int x = 0, unsigned int y = 0);
		
	private:
		unsigned int x;
		unsigned int y;
	
	/**
     	* Overloading of the output stream operator << to print a point.
     	* @param os The output stream.
     	* @param p The point to be printed.
    	* @return The output stream.
     	*/
	friend std::ostream& operator<<(std::ostream& os, Point const& p);
	/**
     	* Overloading of the input stream operator >> to read a point.
     	* @param is The input stream.
     	* @param p The point to be read.
     	* @return The input stream.
     	*/
	friend std::istream& operator>>(std::istream& is, Point& p);
	/**
     	* Overloading of the equality operator == to compare two points.
     	* @param lhs The first point.
     	* @param rhs The second point.
     	* @return True if the two points are equal, false otherwise.
     	*/
	friend bool operator==(const Point& lhs, const Point& rhs);
	/**
     	* Overloading of the inequality operator != to compare two points.
     	* @param lhs The first point.
     	* @param rhs The second point.
     	* @return True if the two points are not equal, false otherwise.
     	*/
	friend bool operator!=(const Point& lhs, const Point& rhs);
	/**
     	* Overloading of the addition operator + to add two points.
     	* @param lhs The first point.
     	* @param rhs The second point.
     	* @return The sum of the two points.
     	*/
	friend Point operator+(const Point& lhs, const Point& rhs);
	/**
     	* Overloading of the subtraction operator - to subtract two points.
     	* @param lhs The first point.
     	* @param rhs The second point.
     	* @return The difference of the two points.
     	*/
	friend Point operator-(const Point& lhs, const Point& rhs);
	/**
     	* Overloading of the addition operator + to add a point and an unsigned int.
     	* @param lhs The point.
     	* @param rhs The unsigned int.
     	* @return The sum of the point and the unsigned int.
     	*/
	friend Point operator+(const Point& lhs, const unsigned int& rhs);
	/**
     	* Overloading of the subtraction operator - to subtract an unsigned int from a point.
     	* @param lhs The point.
     	* @param rhs The unsigned int.
	* @return The difference of the point and the unsigned int.
     	*/
	friend Point operator-(const Point& lhs, const unsigned int& rhs);
};

#endif

