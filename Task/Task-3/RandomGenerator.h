#pragma once 

#include "Generator.h" 
#include <random> 

namespace miit::algebra
{

    /**
    * @brief A generator that produces random integers within a specified range.
    */
    class RandomGenerator : public Generator
    {
    private:
        std::uniform_int_distribution<int> distribution;  
        std::mt19937 generator; 

    public:
        /**
        * @brief Constructor for RandomGenerator.
        * @param min The minimum value for generated integers.
        * @param max The maximum value for generated integers.
        */
        RandomGenerator(const int min, const int max);

        /**
        * @brief Generate a random integer within the specified range.
        * @return The generated integer.
        */
        int generate() override;
    };
}
