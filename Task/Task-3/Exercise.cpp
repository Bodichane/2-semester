#include "Exercise.h"
#include <iostream>
#include <sstream>

namespace miit::algebra {
    Exercise::Exercise(Matrix<int>, Generator* generator) : matrix(matrix), generator(generator) {}

    Exercise::~Exercise() {
        delete generator; 
    }
}
