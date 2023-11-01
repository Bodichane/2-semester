#pragma once

#include <iostream>
#include <sstream>

class Form
{
    public:
        /**
        * Default destructor.
        */
        virtual ~Form() = 0;
        /**
        * Returns a string representation of the form.
        * @return The string representation of the form.
        */
        virtual std::string ToString() const = 0;
};


