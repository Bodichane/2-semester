#include "Form.h"

Form::~Form()
{

}

void Form::Draw() const
{
	std::cout << ToString() << std::endl;
}

void Form::Read(std::istream& is)
{
	std::string str;
	std::getline(is, str);
	FromString(str);
}
