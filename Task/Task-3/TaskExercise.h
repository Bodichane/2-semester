#pragma once

#include "Exercise.h"

namespace miit::algebra {
    class TaskExercise : public Exercise {
    public:
        /*
        * \brief Constructor for TaskExercise.
        * \param matrix Represents the matrix.
        * \param generator Pointer to a Generator for initializing the matrix.
        */
        TaskExercise(Matrix<int> matrix, Generator* generator);

        void Task1() override;
        void Task2() override;
    };
}
