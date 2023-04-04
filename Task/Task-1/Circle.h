#ifndef HEADER_CIRCLE
#define HEADER_CIRCLE
#include "Form.h"
#include "Point.h"

class Circle : public Form
{
	public:
		/**
     		* Default constructor. Creates a circle with radius zero and center at (0, 0).
     		*/
		Circle();
		/**
	     	* Constructor. Creates a circle with the given radius and center.
	     	* @param radius The radius of the circle.
	     	* @param center The center of the circle.
		* @throws std::invalid_argument when radius is negative.
	     	*/
		Circle(int radius, const Point& center);
		/**
	     	* Returns a string representation of the circle.
	     	* @return The string representation of the circle.
	     	*/
		std::string ToString() const override;

	int radius;
	Point center;
};

#endif

