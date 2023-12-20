#include "TaskExercise.h"

namespace miit::algebra {
    TaskExercise::TaskExercise(Matrix<int> matrix, Generator* generator) : Exercise(matrix, generator) {}

    void TaskExercise::Task1() {
        for (size_t i = 0; i < matrix.getRows(); ++i) {
            for (size_t j = 0; j < matrix.getColumns(); ++j) {
                matrix[i][j] = generator.generate();
            }
        }
    }
    void TaskExercise::Task2() {
        std::cout << "Task 2 Result: Matrix elements in a single line:\n";
    std::cout << matrix.toFlatString() << "\n";
    }
} 
