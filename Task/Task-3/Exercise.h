#pragma once

#include "Matrix.h"
#include "Generator.h"
#include <string>

namespace miit::algebra {
    /**
    * @brief Represents an exercise involving a matrix and a generator.
    */
    class Exercise {
    protected:
        Matrix<int> matrix;     
        Generator* generator;   

    public:
        /**
        * @brief Constructor for Exercise.
        * @param matrix Represents the matrix.
        * @param generator Pointer to a Generator for initializing the matrix.
        */
        Exercise(Matrix<int> matrix, Generator* genarator);

        /**
        * @brief Destructor for Exercise.
        */
        virtual ~Exercise();

        /**
        * @brief Pure virtual function representing the first task of the exercise.
        */
        virtual void Task1() = 0;
        /**
        * @brief Pure virtual function representing the second task of the exercise.
        */
        virtual void Task2() = 0;
    };
}
