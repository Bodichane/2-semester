#include "Exercise.h"
#include <iostream>
#include <sstream>

namespace miit::algebra {
    Exercise::Exercise(Matrix<int>, Generator* genarator) : matrix(matrix), generator(genarator) {}

    Exercise::~Exercise() {
        delete generator; 
    }
}
