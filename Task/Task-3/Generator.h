#pragma once

namespace miit::algebra {
    /*
    * \brief Abstract base class representing a generator for matrix elements.
    */
    class Generator
    {
    public:
        /*
        * \brief Virtual destructor for Generator (pure virtual).
        */
        virtual ~Generator() = 0 {};

        /**
        * \brief Pure virtual function to generate an integer.
        * \return The generated integer.
        */
        virtual int generate() = 0;
    };
}