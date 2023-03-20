#ifndef HEADER_FORM
#define HEADER_FORM
#include <iostream>
#include <sstream>

class Form
{
    public:
        virtual ~Form();
        virtual std::string ToString() const = 0;
        virtual void FromString(const std::string& str) = 0;
        virtual void Draw() const;
        virtual void Read(std::istream& is);
};

#endif

