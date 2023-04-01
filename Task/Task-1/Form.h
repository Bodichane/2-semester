#ifndef HEADER_FORM
#define HEADER_FORM
#include <iostream>
#include <sstream>

class Form
{
    public:
        virtual ~Form() = 0;
        virtual std::string ToString() const = 0;
};

#endif

