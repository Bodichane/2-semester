#pragma once

#include "Exercise.h"

namespace miit::algebra {
    class Task1Exercise : public Exercise {
    public:
        Task1Exercise(Generator* generator, int size);

        void Task1() override;
    };
}