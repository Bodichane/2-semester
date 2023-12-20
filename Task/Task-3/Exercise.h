#pragma once

#include "Matrix.h"
#include "Generator.h"
#include <string>

namespace miit::algebra {
    /*
    * \brief Represents an exercise involving a matrix and a generator.
    */
    class Exercise {
    protected:
        Matrix<int> matrix;     
        Generator* generator;   

    public:
        /*
        * \brief Constructor for Exercise.
        * \param generator Pointer to a Generator for initializing the matrix.
        * \param size Size of the matrix (assumes a square matrix).
        */
        Exercise(Generator* generator, int size);

        /**
        * \brief Destructor for Exercise.
        */
        virtual ~Exercise();

        /*
        * \brief Pure virtual function representing the first task of the exercise.
        */
        virtual void Task1() = 0;

        /*
        * \brief Pure virtual function representing the second task of the exercise.
        */
        virtual void Task2() = 0;
    };
}