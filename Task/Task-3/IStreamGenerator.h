#pragma once 

#include "Generator.h" 
#include <iostream> 

namespace miit::algebra
{
    /*
    * \brief A generator that reads integers from an input stream.
    */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in;  

    public:
        /*
        * \brief Constructor for IStreamGenerator.
        * \param in The input stream to read from (default is std::cin).
        */
        IStreamGenerator(std::istream& in = std::cin);

        /**
        * \brief Generates an integer by reading from the input stream.
        * \return The generated integer.
        */
        int generate() override;
    };
}