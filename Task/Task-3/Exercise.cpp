#include "Exercise.h"

namespace miit::algebra {
    Exercise::Exercise(Matrix<int>, Generator* genarator) : matrix(matrix), generator(genarator) {}

    Exercise::~Exercise() {}
}
