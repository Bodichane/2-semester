#ifndef HEADER_CIRCLE
#define HEADER_CIRCLE
#include "Form.h"
#include "Point.h"

class Circle : public Form
{
	public:
		Circle();
		Circle(unsigned int radius, const Point& center);
		std::string ToString() const override;

	unsigned int radius;
	Point center;
};

#endif

