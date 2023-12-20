#include "Exercise.h"
#include <iostream>
#include <sstream>

namespace miit::algebra {
    Exercise::Exercise(Generator* generator, int size) : generator(generator), matrix(size, size) {
        if (generator) {
            matrix << *generator;
        }
    }

    Exercise::~Exercise() {
        delete generator; 
    }
}
