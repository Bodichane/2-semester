#ifndef HEADER_CIRCLE
#define HEADER_CIRCLE
#include "Form.h"
#include "Point.h"

class Circle : public Form, Point
{
	public:
		Circle();
		Circle(unsigned int radius, const Point& center);
		string ToString() const override;
		void FromString(const std::string& str) override;
		static bool Validate(unsigned int radius);
		static void ValidateAndThrow(unsigned int radius);

	unsigned int radius;
	Point center;
};

#endif

